int pin_Out_S0 = 8;
int pin_Out_S1 = 9;
int pin_Out_S2 = 10;
int pin_In_Mux1 = 11;
int Mux1_State[8] = {0};

void setup() {
  pinMode(pin_Out_S0, OUTPUT);
  pinMode(pin_Out_S1, OUTPUT);
  pinMode(pin_Out_S2, OUTPUT);
  pinMode(pin_In_Mux1, INPUT);
  Serial.begin(9600);
}

void loop() {
  updateMux1();
  for(int i = 0; i < 8; i ++) {
    if(i == 7) {
      Serial.println(Mux1_State[i]);
    } else {
      Serial.print(Mux1_State[i]);
    }
  }
}

void updateMux1 () {
  for (int i = 0; i < 8; i++){
    digitalWrite(pin_Out_S0, HIGH && (i & B00000001));
    digitalWrite(pin_Out_S1, HIGH && (i & B00000010));
    digitalWrite(pin_Out_S2, HIGH && (i & B00000100));
    Mux1_State[i] = digitalRead(pin_In_Mux1);
  }
}

