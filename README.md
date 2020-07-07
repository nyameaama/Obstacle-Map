# Obstacle-Map-
2D and 3D obstacle mapper for embedded applications

### How to use
* In this sketch, data is read from ultrasonic sensor into a Map2D object

    //Map2D object
    OBSTACLE_MAP *newObj = new OBSTACLE_MAP;

    //Variable holding value
    double new_reading = ULTRASONIC_NEW();

    //Variable holding measurement angle
    double angle = GET_ANGLE();

    //Call Map function
    newObj -> ADD_TO_MAP(MAP2D(INIT),angle,new_reading);
