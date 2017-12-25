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

#define MAX_X_ROTATION 1.3
#define MIN_X_ROTATION -1.3

namespace gps {
    
    
    
    class Camera
    {
    public:
        //Camera constructor
		Camera();
        Camera(glm::vec3 cameraPosition);
		Camera(glm::vec3 cameraPosition, float xRotation, float yRotation);
        //return the view matrix, using glm::lookAt
        glm::mat4 getViewMatrix();
		void SetPosition(glm::vec3 position);
		void SetRotation(GLfloat xRotation, GLfloat yRotation);
        
    private:
		void updateCameraTarget();
        glm::vec3 cameraPosition;
        glm::vec3 cameraTarget;
		GLfloat xRotation;
		GLfloat yRotation;
		GLuint viewMatrixLoc;
    };
    
}

#endif /* Camera_hpp */
