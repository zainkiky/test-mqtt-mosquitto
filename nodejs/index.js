const mqtt = require('mqtt');

const MQTT_SERVER = 'mqtt://test.mosquitto.org';
const MQTT_PORT = 1883;
const ROUTING_KEY = 'buattestinimah/nodemcu/v1';
const MESSAGE = 'Hallow dari NODEJS 1';

const client = mqtt.connect(`${MQTT_SERVER}:${MQTT_PORT}`);

client.on('connect', () => {
  console.log('Connected to MQTT broker');
  client.publish(ROUTING_KEY, MESSAGE, (err) => {
    if (err) {
      console.error('Failed to publish message:', err);
    } else {
      console.log(`Message "${MESSAGE}" published to "${ROUTING_KEY}"`);
    }
    client.end();
  });
});

client.on('error', (err) => {
  console.error('Failed to connect to MQTT broker:', err);
});
