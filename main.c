#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PWM 22

#define ANGULO_0 500
#define ANGULO_90 1467
#define ANGULO_180 2399

volatile uint8_t cont=1;
volatile uint16_t inc_angulo=5;
bool incrementa=true;

uint slice;

void setup_pwm();

int64_t turn_off_callback(alarm_id_t id, void *user_data);


int main(){

  setup_pwm();

  pwm_set_gpio_level(SERVO_PWM,ANGULO_180);
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,ANGULO_90);
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,ANGULO_0);

  add_alarm_in_ms(5000,turn_off_callback,NULL,false);
  while(1){
    
    sleep_ms(1000);
  }
}

void setup_pwm(){
  gpio_set_function(SERVO_PWM, GPIO_FUNC_PWM);
  slice=pwm_gpio_to_slice_num(SERVO_PWM);
  pwm_set_clkdiv(slice,125.0);
  pwm_set_wrap(slice,19999);
  pwm_set_gpio_level(SERVO_PWM,2399);
  pwm_set_enabled(slice,true);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data){
  if(incrementa){

    pwm_set_gpio_level(SERVO_PWM,ANGULO_0 + inc_angulo);

    if((inc_angulo + ANGULO_0) >= ANGULO_180){
      incrementa=false;
      inc_angulo=5;
    }
  }else{
    pwm_set_gpio_level(SERVO_PWM,ANGULO_180 - inc_angulo);

    if((ANGULO_180 - inc_angulo) <= ANGULO_0){
      incrementa=true;
      inc_angulo=5;
    }
  }
  inc_angulo+=5;
  
  return 10000;
}