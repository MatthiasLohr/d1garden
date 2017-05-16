
#include "webserver.h"

ESP8266WebServer webserver = ESP8266WebServer(80);

void webserverIndex() {
  webserver.send(200, "text/plain", "Hello world!");
}
