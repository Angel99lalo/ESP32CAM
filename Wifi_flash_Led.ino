// Inicialización del programa
void setup() {
  //Configuración de pines
  pinMode (statusLedPin, OUTPUT);// Se configura el pin como salida
  pinMode (flashLedPin, OUTPUT);// Se configura el pin como salida
  digitalWrite (statusLedPin, HIGH);// Se comienza con el led apagado
  digitalWrite (flashLedPin, LOW);// Se comienza con el led apagado
  pinMode(LedPin , OUTPUT);//Se configura el pin como salida 
  digitalWrite (LedPin, HIGH);//Se comienza con el led encendido 
  

  //Inicialización de comunicación serial
  Serial.begin (115200);//Velocidad de comunicacion de recepcion y transmicion de datos
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
 
  // Iniciar el WiFi
  WiFi.begin(ssid, password); // Esta es la función que realiz la conexión a WiFi
 
  while (WiFi.status() != WL_CONNECTED) { // Este bucle espera a que se realice la conexión
    digitalWrite (statusLedPin, HIGH);
    delay(500); //dado que es de suma importancia esperar a la conexión, debe usarse espera bloqueante
    digitalWrite (statusLedPin, LOW);
    Serial.print(".");  // Indicador de progreso
    delay (5);
  }

  // Cuando se haya logrado la conexión, el programa avanzará, por lo tanto, puede informarse lo siguiente
  Serial.println();
  Serial.println("WiFi conectado");
  Serial.println("Direccion IP: ");
  Serial.println(WiFi.localIP());

  // Si se logro la conexión, encender led
  if (WiFi.status () > 0){
  digitalWrite (flashLedPin, LOW);
  }
  timeLast = millis (); // Inicia el control de tiempo
}// Fin del void setup 

//Cuerpo del programa, bucle principal
void loop() {
  timeNow = millis ();  // Seguimiento de tiempo
  if ((timeNow - timeLast > wait) && statusLed == 0){// Comprobar el encendido del flash
    digitalWrite (flashLedPin, HIGH);// Encender el flash
    statusLed = 1;//Indicar que el led flash se encuentra encendido
    timeLast = millis (); // Inicia el control de tiempo
  }
  if ((timeNow - timeLast > wait) && statusLed == 1){
    digitalWrite (flashLedPin, LOW);// Apagar Led el flash
    statusLed = 0;//Indicar que el led flash se encuentra apagado
    timeLast = millis (); // Inicia el control de tiempo
  }
  
}// Fin de void loop
