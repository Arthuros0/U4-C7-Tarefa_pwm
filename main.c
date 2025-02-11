#include "pico/stdlib.h"
#include "hardware/pwm.h"


//Atenção, se deseja usar o programa na BitDogLab Comente a linha #define SERVO_PWM 22 e descomente a linha #define SERVO_PWM 12
//#define SERVO_PWM 12
#define SERVO_PWM 22

//Duty-cicle dos angulos do servo motor
#define ANGULO_0 500
#define ANGULO_90 1467
#define ANGULO_180 2399

//Varialve de incremento e decremento do angulo, e boleano que decide se vai ser decrementado ou incrementado
volatile uint16_t inc_angulo=5;
bool incrementa=true;

uint slice; //Armazena o slice do pino pwm

void setup_pwm(); //Configura o pwm

int64_t angulo_callback(alarm_id_t id, void *user_data); //Função de callback para incrementar ou decrementar angulo

int main(){

  setup_pwm();

  pwm_set_gpio_level(SERVO_PWM,ANGULO_180); //Definição do angulo do servo motor para 180º
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,ANGULO_90); //Definição do angulo do servo motor para 90º
  sleep_ms(5000);

  pwm_set_gpio_level(SERVO_PWM,ANGULO_0); //Definição do angulo do servo motor para 0º

  add_alarm_in_ms(5000,angulo_callback,NULL,false); //Inicialização do alarme de callback
  while(1){
    
    sleep_ms(1000);
  }
}

void setup_pwm(){
  gpio_set_function(SERVO_PWM, GPIO_FUNC_PWM); //Definição do pino para função pwm
  slice=pwm_gpio_to_slice_num(SERVO_PWM); //Armazenando slice do pino pwm
  pwm_set_clkdiv(slice,125.0); //Configura o divisor de clock
  pwm_set_wrap(slice,19999);  //Configura o valor máximo de contagem
  pwm_set_gpio_level(SERVO_PWM,ANGULO_90); //Define o angulo inicial em 90º
  pwm_set_enabled(slice,true); //Ativa o PWM
}

int64_t angulo_callback(alarm_id_t id, void *user_data){
  
  //Se o incrementa for true, a variável auxiliar inc_angulo é incrementada de 5 em 5 até que a soma do inc_angulo mais ANGULO_0
  //seja maior ou igual a ANGULO_180, quando isso ocorrer incrementa recebe falso e inc_angulo volta ao valor 5.
  //A partir daí vale a lógica do else onde inc_angulo é incrementado de 5 em 5 , mas subtrai ANGULO_180 até que 
  //ANGULO_180 - inc_angulo seja menor ou igual a ANGULO_0, nesse caso incrementa recebe true e inc_angulo recebe 5

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
  
  return 10000; //Retorna 10000 us (10ms) que é o tempo da próxima chamada da função
}