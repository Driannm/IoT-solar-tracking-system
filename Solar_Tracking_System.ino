#include <Servo.h>

// Inisialisasi servo
Servo servoX;
Servo servoY;

// Pin untuk sensor cahaya (LDR)
const int ldrPin1 = A0;
const int ldrPin2 = A1;

// Batas toleransi untuk menentukan pergerakan servo
const int threshold = 10;

// Variabel untuk menyimpan nilai dari sensor cahaya
int ldrValue1, ldrValue2;

// Posisi awal servo
int posX = 90;
int posY = 90;

void setup() {
  // Menghubungkan servo dengan pin yang sesuai
  servoX.attach(8);
  servoY.attach(9);

  // Mengatur posisi awal servo
  servoX.write(posX);
  servoY.write(posY);

  // Inisialisasi komunikasi serial
  Serial.begin(9600);
}

void loop() {
  // Membaca nilai dari sensor cahaya
  ldrValue1 = analogRead(ldrPin1);
  ldrValue2 = analogRead(ldrPin2);

  // Menampilkan nilai sensor cahaya di Serial Monitor
  Serial.print(" | LDR1: "); Serial.print(ldrValue1);
  Serial.print(" | LDR2: "); Serial.print(ldrValue2);

  // Menghitung selisih nilai sensor
  int diffX = ldrValue1 - ldrValue2;
  int diffY = ldrValue1 - ldrValue2;

  // Menentukan pergerakan servo berdasarkan selisih nilai sensor
  if (abs(diffX) > threshold) {
    if (diffX > 0) {
      posX += 10;
    } else {
      posX -= 10;
    }
  }

  if (abs(diffY) > threshold) {
    if (diffY > 0) {
      posY += 3;
    } else {
      posY -= 3;
    }
  }

  // Batasan posisi servo
  posX = constrain(posX, 0, 180);
  posY = constrain(posY, 0, 180);

  // Menggerakkan servo ke posisi yang telah ditentukan
  servoX.write(posX);
  servoY.write(posY);

  // Delay untuk memberikan waktu servo bergerak
  delay(50);
}
