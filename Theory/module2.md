# Module 2: IoT Fundamentals & Arduino Programming - Theory Solutions

### Q11. 4-Layer IoT Architecture Diagram

The Internet of Things (IoT) architecture organizes data pathways from physical interactions up to high-level cloud software processing systems.

```text
+-------------------------------------------------------------+
| 4. APPLICATION LAYER                                        |
|    - Smart Home Dashboards, Mobile Apps, Analytics UI       |
+-------------------------------------------------------------+
                              ▲
                              │ Data Delivery / API calls
                              ▼
+-------------------------------------------------------------+
| 3. PROCESSING LAYER                                         |
|    - Cloud Databases, Fog/Edge Computing, Core Data Parsing |
+-------------------------------------------------------------+
                              ▲
                              │ MQTT / HTTP via Wi-Fi/Cellular
                              ▼
+-------------------------------------------------------------+
| 2. NETWORK LAYER                                            |
|    - Gateways, Routers, Communication Protocols (BLE, Wi-Fi)|
+-------------------------------------------------------------+
                              ▲
                              │ SPI / I2C / Analog Signals
                              ▼
+-------------------------------------------------------------+
| 1. PERCEPTION LAYER                                         |
|    - Physical Sensors, Actuators, Microcontrollers (HW)      |
+-------------------------------------------------------------+