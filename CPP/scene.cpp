/***
 Assignment-3: Geometric Modeling of a Scene
 
 Name: Zafiris, Serena
 
 Collaborators: Skeleton Code Courtesy of Alex Wong
 
 Project Summary: I wrote the defnintions for all the translation, scaling and rotation matrices.
 I then used them to create a unit cube from an initial plane. I then used the unit cube to build the scene.
 I also implemented the camera view and rotated the scene.
 ***/


#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#pragma GCC diagnostic pop

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

// If a float is < EPSILON or > -EPILSON then it should be 0
float EPSILON = 0.000001;
// theta is the angle to rotate the scene
float THETA = 0.0;
// Vector placeholders for the scene and color array
vector<GLfloat> SCENE;
vector<GLfloat> COLOR;

/**************************************************
 *  Rectangular Prisms via Hierarchical Modeling  *
 *                                                *
 *  using planes as building blocks, build a unit *
 *  cube with transformations that will serve as  *
 *  a primitive for modeling objects in the scene *
 *                                                *
 *************************************************/

// Initializes a square plane of unit lengths
vector<GLfloat> init_plane() {
    vector<GLfloat> vertices = {
        +0.5,   +0.5,   +0.0,
        -0.5,   +0.5,   +0.0,
        -0.5,   -0.5,   +0.0,
        +0.5,   -0.5,   +0.0
    };
    return vertices;
}

// Converts degrees to radians for rotation
float deg2rad(float d) {
    return (d*M_PI) / 180.0;
}

// Converts a vector to an array
GLfloat* vector2array(vector<GLfloat> vec) {
    GLfloat* arr = new GLfloat[vec.size()];
    for (int i = 0; i < vec.size(); i++) {
        arr[i] = vec[i];
    }
    return arr;
}

// Converts Cartesian coordinates to homogeneous coordinates
vector<GLfloat> to_homogeneous_coord(vector<GLfloat> cartesian_coords) {
    vector<GLfloat> result;
    for (int i = 0; i < cartesian_coords.size(); i++) {
        result.push_back(cartesian_coords[i]);
        if ((i+1) % 3 == 0) {
            result.push_back(1.0);
        }
    }
    return result;
}

// Converts Cartesian coordinates to homogeneous coordinates
vector<GLfloat> to_cartesian_coord(vector<GLfloat> homogeneous_coords) {
    vector<GLfloat> result;
    for (int i = 0; i < homogeneous_coords.size(); i++) {
        if ((i+1) % 4 == 0) {
            continue;
        } else {
            result.push_back(homogeneous_coords[i]);
        }
    }
    return result;
}

// Definition of a translation matrix
vector<GLfloat> translation_matrix (float dx, float dy, float dz) {
    vector<GLfloat> translate_mat;
    translate_mat = {
        1, 0, 0, dx,
        0, 1, 0, dy,
        0, 0, 1, dz,
        0, 0, 0, 1
    };
    return translate_mat;
}

// Definition of a scaling matrix
vector<GLfloat> scaling_matrix (float sx, float sy, float sz) {
    vector<GLfloat> scale_mat;
    scale_mat = {
        sx, 0, 0, 0,
        0, sy, 0, 0,
        0, 0, sz, 0,
        0, 0, 0, 1
    };
    return scale_mat;
}

// Definition of a rotation matrix about the x-axis theta degrees
vector<GLfloat> rotation_matrix_x (float theta) {
    vector<GLfloat> rotate_mat_x;
    theta = deg2rad(theta);
    rotate_mat_x = {
        1, 0, 0, 0,
        0, cos(theta), -sin(theta), 0,
        0, sin(theta), cos(theta),  0,
        0, 0, 0, 1
    };
    return rotate_mat_x;
}


// Definition of a rotation matrix about the y-axis by theta degrees
vector<GLfloat> rotation_matrix_y (float theta) {
    vector<GLfloat> rotate_mat_y;
    theta = deg2rad(theta);
    rotate_mat_y = {
        cos(theta), 0, sin(theta), 0,
        0, 1, 0, 0,
        -sin(theta), 0, cos(theta),  0,
        0, 0, 0, 1
    };
    return rotate_mat_y;
}


// Definition of a rotation matrix about the z-axis by theta degrees
vector<GLfloat> rotation_matrix_z (float theta) {
    vector<GLfloat> rotate_mat_z;
    theta = deg2rad(theta);
    rotate_mat_z = {
        cos(theta), -sin(theta), 0, 0,
        sin(theta), cos(theta), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    return rotate_mat_z;
}

// Perform matrix multiplication for A B
vector<GLfloat> mat_mult(vector<GLfloat> A, vector<GLfloat> B) {
    vector<GLfloat> result;
    // TODO: Compute matrix multiplication of A B
    for (int b = 0; b < B.size()/4; b++) {
        for (int a = 0; a < 4; a++) {
            float element_wise_sum = 0.0;
            for (int k = 0; k < 4; k++) {
                float element_wise = A[a*4+k]*B[b*4+k];
                if (element_wise < EPSILON && element_wise > -1.0*EPSILON) {
                    element_wise = 0.0;
                }
                element_wise_sum += element_wise;
            }
            result.push_back(element_wise_sum);
        }
    }
    return result;
}

// Builds a unit cube centered at the origin
vector<GLfloat> build_cube() {
    vector<GLfloat> result;
    vector<GLfloat> plane;
    vector<GLfloat> front;
    vector<GLfloat> left;
    vector<GLfloat> right;
    vector<GLfloat> back;
    vector<GLfloat> top;
    vector<GLfloat> bottom;
    
    plane = to_homogeneous_coord(init_plane());
    
    front = mat_mult(translation_matrix(0.0, 0.0, 0.5), plane);
    left = mat_mult(rotation_matrix_y(-90.0), plane);
    left = mat_mult(translation_matrix(-0.5, 0.0, 0.0), left);
    right = mat_mult(rotation_matrix_y(90.0), plane);
    right = mat_mult(translation_matrix(0.5, 0.0, 0.0), right);
    back = mat_mult(rotation_matrix_y(180.0), plane);
    back = mat_mult(translation_matrix(0.0, 0.0, -0.5), back);
    top = mat_mult(rotation_matrix_x(-90.0), plane);
    top = mat_mult(translation_matrix(0.0, 0.5, 0.0), top);
    bottom = mat_mult(rotation_matrix_x(90.0), plane);
    bottom = mat_mult(translation_matrix(0.0, -0.5, 0.0), bottom);
    
    
    front = to_cartesian_coord(front);
    left = to_cartesian_coord(left);
    right = to_cartesian_coord(right);
    back = to_cartesian_coord(back);
    top = to_cartesian_coord(top);
    bottom = to_cartesian_coord(bottom);
    
    result.insert(result.end(), front.begin(), front.end());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    result.insert(result.end(), back.begin(), back.end());
    result.insert(result.end(), top.begin(), top.end());
    result.insert(result.end(), bottom.begin(), bottom.end());
    
    return result;
}

/**************************************************
 *            Camera and World Modeling           *
 *                                                *
 *  create a scene by applying transformations to *
 *  the objects built from planes and position    *
 *  the camera to view the scene by setting       *
 *  the projection/viewing matrices               *
 *                                                *
 *************************************************/

void setup() {
    // Enable the vertex array functionality
    glEnableClientState(GL_VERTEX_ARRAY);
    // Enable the color array functionality (so we can specify a color for each vertex)
    glEnableClientState(GL_COLOR_ARRAY);
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    // Set up some default base color
    glColor3f(0.5, 0.5, 0.5);
    // Set up white background
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void init_camera() {
    // Camera parameters
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, 1.0, 1.0, 30.0);
    gluLookAt(4.0, 3.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// Construct the scene using objects built from cubes/prisms
vector<GLfloat> init_scene() {
    vector<GLfloat> scene;
    vector<GLfloat> homog_plane;
    vector<GLfloat> couch_cushion;
    vector<GLfloat> rt_couch_cushion;
    vector<GLfloat> lf_couch_cushion;
    vector<GLfloat> back_couch_cushion;
    vector<GLfloat> tv;
    vector<GLfloat> lamp_base;
    vector<GLfloat> lamp_pole;
    vector<GLfloat> lampshade;
    vector<GLfloat> table_base;
    vector<GLfloat> tabletop;

    homog_plane = to_homogeneous_coord(build_cube());
    
    // Scaling and Translating the points
    couch_cushion = mat_mult(scaling_matrix(1.5, 0.5, 1.0), homog_plane);
    rt_couch_cushion = mat_mult(scaling_matrix(0.5, 1.0, 1.0), homog_plane);
    rt_couch_cushion = mat_mult(translation_matrix(1.0, 0.0, 0.0), rt_couch_cushion);
    lf_couch_cushion = mat_mult(translation_matrix(-2.0, 0.0, 0.0), rt_couch_cushion);
    back_couch_cushion = mat_mult(scaling_matrix(2.5, 2.0, 0.3), homog_plane);
    back_couch_cushion = mat_mult(translation_matrix(0.0, 0.5, -0.65), back_couch_cushion);
    tv = mat_mult(scaling_matrix(2.0, 1.3, 0.2), homog_plane);
    tv = mat_mult(rotation_matrix_y(180), tv);
    tv = mat_mult(translation_matrix(0.0, 0.75, 2.5), tv);
    table_base = mat_mult(scaling_matrix(0.5, 0.5, 0.5), homog_plane);
    table_base = mat_mult(translation_matrix(2.0, -0.25, 0.0), table_base);
    tabletop = mat_mult(scaling_matrix(1.0, 0.25, 1.0), homog_plane);
    tabletop = mat_mult(translation_matrix(2.0, 0.25, 0.0), tabletop);
    lamp_base = mat_mult(scaling_matrix(1.0, 0.1, 1.0), homog_plane);
    lamp_base = mat_mult(translation_matrix(-2.0, -0.45, 0.0), lamp_base);
    lamp_pole = mat_mult(scaling_matrix(0.1, 3.0, 0.1), homog_plane);
    lamp_pole = mat_mult(translation_matrix(-2.0, 1.0, 0.0), lamp_pole);
    lampshade = mat_mult(scaling_matrix(1.0, 0.75, 1.0), homog_plane);
    lampshade = mat_mult(translation_matrix(-2.0, 2.75, 0.0), lampshade);
    
    // Cartesian
    couch_cushion = to_cartesian_coord(couch_cushion);
    rt_couch_cushion = to_cartesian_coord(rt_couch_cushion);
    lf_couch_cushion = to_cartesian_coord(lf_couch_cushion);
    back_couch_cushion = to_cartesian_coord(back_couch_cushion);
    tv = to_cartesian_coord(tv);
    table_base = to_cartesian_coord(table_base);
    tabletop = to_cartesian_coord(tabletop);
    lamp_base = to_cartesian_coord(lamp_base);
    lamp_pole = to_cartesian_coord(lamp_pole);
    lampshade = to_cartesian_coord(lampshade);
    
    // Adding to the scene
    scene.insert(scene.end(), couch_cushion.begin(), couch_cushion.end());
    scene.insert(scene.end(), rt_couch_cushion.begin(), rt_couch_cushion.end());
    scene.insert(scene.end(), lf_couch_cushion.begin(), lf_couch_cushion.end());
    scene.insert(scene.end(), back_couch_cushion.begin(), back_couch_cushion.end());
    scene.insert(scene.end(), tv.begin(), tv.end());
    scene.insert(scene.end(), table_base.begin(), table_base.end());
    scene.insert(scene.end(), tabletop.begin(), tabletop.end());
    scene.insert(scene.end(), lamp_base.begin(), lamp_base.end());
    scene.insert(scene.end(), lamp_pole.begin(), lamp_pole.end());
    scene.insert(scene.end(), lampshade.begin(), lampshade.end());
    return scene;
}

// Construct the color mapping of the scene
vector<GLfloat> init_color(vector<GLfloat> scene) {
    vector<GLfloat> colors;
    for (int i = 0; i < scene.size(); i++) {
        colors.push_back(static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
    }
    return colors;
}

void display_func() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Rotate the scene using the scene vector
    vector<GLfloat> homogenousPoints;
    homogenousPoints = to_homogeneous_coord(init_scene());
    homogenousPoints = mat_mult(rotation_matrix_y(THETA), homogenousPoints);
    SCENE = to_cartesian_coord(homogenousPoints);
    
    
    GLfloat* scene_vertices = vector2array(SCENE);
    GLfloat* color_vertices = vector2array(COLOR);
    // Pass the scene vertex pointer
    glVertexPointer(3,                // 3 components (x, y, z)
                    GL_FLOAT,         // Vertex type is GL_FLOAT
                    0,                // Start position in referenced memory
                    scene_vertices);  // Pointer to memory location to read from
    
    // Pass the color vertex pointer
    glColorPointer(3,                   // 3 components (r, g, b)
                   GL_FLOAT,            // Vertex type is GL_FLOAT
                   0,                   // Start position in referenced memory
                   color_vertices);     // Pointer to memory location to read from
    
    // Draw quad point planes: each 4 vertices
    glDrawArrays(GL_QUADS, 0, 4 * 60);
    
    glFlush();            //Finish rendering
    glutSwapBuffers();
}

void idle_func() {
    THETA = THETA + 0.02;
    display_func();
}

int main (int argc, char **argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    // Create a window with rendering context and everything else we need
    glutCreateWindow("Assignment 3");
    
    setup();
    init_camera();
    // Setting global variables SCENE and COLOR with actual values
    SCENE = init_scene();
    COLOR = init_color(SCENE);
    
    // Set up our display function
    glutDisplayFunc(display_func);
    glutIdleFunc(idle_func);
    // Render our world
    glutMainLoop();
    
    // Remember to call "delete" on your dynmically allocated arrays
    // such that you don't suffer from memory leaks. e.g.
    // delete arr;
    
    return 0;
}
