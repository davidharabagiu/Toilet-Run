//
//  Camera.hpp
//
//  Created by CGIS on 28/10/2016.
//  Copyright © 2016 CGIS. All rights reserved.
//	Improved by David Harabagiu aka Smecherus Maximus
//

#define GLM_ENABLE_EXPERIMENTAL

#ifndef Camera_hpp
#define Camera_hpp

#include <iostream>
#include "Input.hpp"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#define MAX_X_ROTATION 1.57
#define MIN_X_ROTATION -1.57
#define SPEED 0.001f

namespace gps {
    
    enum MOVE_DIRECTION {MOVE_FORWARD, MOVE_BACKWARD, MOVE_RIGHT, MOVE_LEFT};
    
    class Camera
    {
    public:
        //Camera constructor
		Camera();
        Camera(glm::vec3 cameraPosition);
		Camera(glm::vec3 cameraPosition, float xRotation, float yRotation);
        //return the view matrix, using glm::lookAt
        glm::mat4 getViewMatrix();
        //update the camera parameters
        void move(MOVE_DIRECTION direction, float speed);
        //yaw - rotate around y axis
        //pitch - rotate around x axis
        void rotate(float pitch, float yaw);
		void update();
        
    private:
		void updateCameraTarget();
		float xRotation = 0;
		float yRotation = 0;
        glm::vec3 cameraPosition;
        glm::vec3 cameraTarget;
		bool movingForward;
		bool movingBackward;
		bool movingLeft;
		bool movingRight;
		GLuint viewMatrixLoc;
    };
    
}

#endif /* Camera_hpp */
