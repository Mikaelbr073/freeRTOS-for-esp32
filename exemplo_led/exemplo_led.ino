 // Definindo que o ESP só vai usar um core 
  #if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0; 
  #else 
  static const BaseType_t app_cpu = 1;
  #endif  


  //Pins 

  //led do arduino
  static const int led_pin = 18; 

  //Task de piscar led 
  void toggleLED(void * parameter){

    while(1){
      digitalWrite(led_pin, HIGH);
      //Dessa forma não bloqueia as outras atividades 
      vTaskDelay(500 / portTICK_PERIOD_MS);
      digitalWrite(led_pin, LOW);
      vTaskDelay(500 / portTICK_PERIOD_MS);
      //tick time é temporizador do hardware
      //alocado para interromper o processo de um intervalo especifico no HD
      //interrupção é conhecido como tick 1ms
    }

  }



void setup() {
  

 pinMode(led_pin, OUTPUT);

 xTaskCreatePinnedToCore(//Usar xTaskCreate no FreeRTOS vanilla


  toggleLED, // Função a ser chamada
  "Toggle LED", // nome da função 
  1024, // Tamanho da pilha de Bytes(min 768bytes para executar uma fun vazia)
  NULL, // Você pode passar um ponteiro 
  1, //prioridade valor min = 0, max = 24
  NULL,// Podemos definir um ponteiro para indetificação na função loop, dessa forma podemos cerificar 
              // Status, uso de memória ou encerrá-la 
  app_cpu    // definindo a cpu usada 

 );



}

void loop() {


  

}
