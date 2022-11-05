int bt[] = {1, 7, 2, 5, 10, 3}; // Burst time inputs
int p[] = {13, 12, 8, 7, 4, 2}; // Processes pin inputs
int size = 6;
float AWT, wt;

void setup() {
  // LEDs Pin configuration
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  ShortestJobFirst(bt, size);
  Serial.begin(9600);
}

void ShortestJobFirst(int a[], int size) {
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size -1; j++) {
      if(a[j] > a[i]){
        int btTemp = a[i];
        int pTemp = p[i];
        a[i] = a[j];
        a[j] = btTemp;
        p[i] = p[j];
        p[j] = pTemp;
      }
    }
  }
}

void loop() {
  for ( int i = 0; i < size; i++) {
    Arrive(p[i], bt[i]); // Arrival of task
  	if (i < size - 1) {
      Wt(bt[i]); // Waiting time
  	}
  }

  Serial.println("Average Waiting Time : ");
  Serial.println(AWT/size); // Prints Average Waiting Time
  Serial.println("End of process. ");
  delay(10000);
}

void Arrive(int task, int burstTime) {
  digitalWrite(task, HIGH);
  delay(burstTime * 1000); // Lights up to burst time
  digitalWrite(task, LOW);
}

void Wt(int waitingTime) {
  wt = wt + waitingTime;
  AWT = AWT + wt;
}
