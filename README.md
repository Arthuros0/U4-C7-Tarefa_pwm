# Tarefa: Controle de Servomotor por PWM

Este repositório contém a implementação da tarefa individual da Unidade 4 | Capítulo 7 (C7O123E), que consiste no controle de um servomotor por PWM utilizando o Raspberry Pi Pico W no simulador Wokwi.

## Descrição da tarefa

A atividade propõe o controle de um servomotor através do módulo PWM do RP2040. O código foi desenvolvido em C utilizando o Pico SDK e executado no simulador Wokwi.

### Requisitos da Atividade

1. Configurar a GPIO 22 com um sinal PWM de aproximadamente 50Hz.

2. Definir o ciclo de trabalho do PWM para:

    - 2.400µs (0,12%) → Posição de 180° (aguardar 5s)

    - 1.470µs (0,0735%) → Posição de 90° (aguardar 5s)

    - 500µs (0,025%) → Posição de 0° (aguardar 5s)

3. Criar uma rotina para movimentação periódica do servomotor entre 0° e 180° com incremento suave de ±5µs e atraso de 10ms.

4. Utilizar a ferramenta BitDogLab para testar o código em um LED RGB na GPIO 12 e descrever a observação.

  ## **Vídeo de Demonstração do Projeto**
Confira a demonstração da tarefa clicando no ícone abaixo:

<a href="https://youtu.be/ztjw6JRl9bY">
  <img src="https://img.icons8.com/color/48/000000/youtube-play.png" alt="YouTube" />
</a>

### Tecnologias Utilizadas

- Raspberry Pi Pico W

- Linguagem C

- Pico SDK

- VS Code

- Simulador Wokwi

- BitDogLab

 ### **Pré-requisitos para utilização**
Certifique-se de que os seguintes itens estão instalados:

1. **Visual Studio Code**  
   - Ambiente de desenvolvimento integrado (IDE) para edição, compilação e depuração do código.

2. **Git**  
   - Ferramenta para versionamento de código e controle de repositórios.  

3. **Extensões do Visual Studio Code**  
   - **C/C++**: Suporte à linguagem C/C++ para análise de código, depuração e IntelliSense.  
   - **CMake Tools**: Para gerenciar e configurar projetos que utilizam o CMake.  
   - **Raspberry Pi Pico**: Extensão para facilitar o desenvolvimento e a comunicação com a placa Raspberry Pi Pico.
   - **Wokwi**: Extensão para simular a Raspberry Pi Pico W.

4. **Versão 2.0.0+ do Raspberry Pi Pico SDK**  
   - Certifique-se de que a versão 2.0.0 ou superior do SDK para Raspberry Pi Pico está instalada.

5. **Opcional: Zadig**  
   - Software necessário para instalar drivers USB.  
   - Permite a conexão via USB da placa Raspberry Pi Pico com o desktop ou notebook.  
---

## **Como executar o Projeto**

### **1. Configuração Inicial**
1. Certifique-se de que todas as dependências acima estão instaladas no seu computador.
2. Clone o repositório do projeto usando os comandos abaixo no terminal:  
   ```bash
   git init
   ```
   ```bash
   git clone https://github.com/Arthuros0/U4-C7-Tarefa_pwm.git
   ```
3. Abra o projeto clonado no VS Code

### **2. Compilação e Carregamento na Placa**
1. Importe e compile a pasta da atividade desejada individualmente usando a extensão Raspberry Pi Pico no **Visual Studio Code**.
2. Após a compilação bem-sucedida, abra o arquivo diagram json e execute a simulação.
