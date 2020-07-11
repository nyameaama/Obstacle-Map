# Obstacle-Map
2D Obstacle Mapper library for embedded applications. 

### About

This library is 

### How to use

* In this sketch, data is read from ultrasonic sensor into a Map2D object

* Create Map2D object

        //Map2D object
        OBSTACLE_MAP *newObj = new OBSTACLE_MAP;

* Sensor Data

        //Variable holding value
        double new_reading = ULTRASONIC_NEW();

        //Variable holding measurement angle
        double angle = GET_ANGLE();

* Initialise Map2D - This method returns a unique ID corresponding to the map

        //Put INIT method in object 
        uint8_t init = newObj -> MAP2D(INIT);

* Call Map function - This method takes in the value and bearing/degree

        //Call Map function
        newObj -> ADD_TO_MAP_2D(init,angle,new_reading);


### Future Release:

* 3D mapping support by augmenting DOF readings with distance/bearing values

* Less memory footprint with greater microcontroller support