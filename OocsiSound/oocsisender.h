#pragma once

#include "OOCSI.h"

class OocsiSender
{
private:
	OOCSI* oocsi;
public:
	OocsiSender(const char* ssid, const char* passw);
  void Ping();
	void Send(char* message);
  void SendInt(int message);
};

OocsiSender::OocsiSender(const char* ssid, const char* passw) 
{
	oocsi = new OOCSI();
	Serial.println("connecting");
	oocsi->connect("ESP-SENSOR", "oocsi.id.tue.nl", ssid, passw);
	oocsi->subscribe("esp-testchannel");
	oocsi->setLogging(true);
	Serial.println("connected");
}

void OocsiSender::Send(char* message) 
{
  Serial.println("sending message");
	oocsi->newMessage("esp-testchannel");
	oocsi->addString("funfact" , message);
	oocsi->sendMessage();
	oocsi->check();
}

void OocsiSender::SendInt(int message) 
{
  Serial.println("sending message");
  oocsi->newMessage("esp-testchannel");
  oocsi->addInt("count" , message);
  oocsi->sendMessage();
  oocsi->check();
}

void OocsiSender::Ping() 
{
  oocsi->check();
}
