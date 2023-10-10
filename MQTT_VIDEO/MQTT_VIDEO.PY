import paho.mqtt.client as mqtt
import serial

ser= serial.Serial('COM7',9600)

def conectado(client, userdata, flags, rc):
    print("estamos conectados al servidor "+str(rc))

    
    client.subscribe("led2023/#")# aqui ponen el topic al que se van a suscribir


def mensaje(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

    if msg.payload == b'1':
       ser.write(b'1\n')
    if msg.payload == b'0':
       ser.write(b'0\n')




client = mqtt.Client()
client.on_connect = conectado
client.on_message = mensaje

client.connect("mqtt-dashboard.com", 1883, 60) # aqui ponene el host del broker

client.loop_forever()