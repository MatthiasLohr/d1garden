
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include "settings.h"

extern ESP8266WebServer webserver;

void webserverIndex();
void webserverStyle();
void webserverUpdate();

#endif
