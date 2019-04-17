/***
 Cartoonify
 
 Name: Zafiris , Serena
 
 Collaborators: Skeleton Code courtesy of Alex Wong
 ***/


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <iostream>
#define GL_SILENCE_DEPRECATION
using namespace std;

class Vertex {
    GLfloat x, y;
public:
    Vertex(GLfloat, GLfloat);
    GLfloat get_y() { return y; };
    GLfloat get_x() { return x; };
};

Vertex::Vertex(GLfloat X, GLfloat Y) {
    x = X;
    y = Y;
}

void setup() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

vector<Vertex> generate_points(vector<Vertex> control_points) {
    vector<Vertex> points;
    points.push_back(control_points.at(0));
    for(int i = 0; i < (control_points.size()-1); i++) {
        float delta_x = control_points[i+1].get_x() - control_points[i].get_x();
        float delta_y = control_points[i+1].get_y() - control_points[i].get_y();
        Vertex quarter_point = Vertex(control_points[i].get_x() + delta_x * 0.25, control_points[i].get_y() + delta_y * 0.25);
        Vertex three_quarter_point = Vertex(control_points[i].get_x() + delta_x * 0.75, control_points[i].get_y() + delta_y * 0.75);
        points.push_back(quarter_point);
        points.push_back(three_quarter_point);
    }
    points.push_back(control_points.back());
    return points;
}

void draw_curve(vector<Vertex> control_points, int n_iter) {
    vector<Vertex> draw_points;
    draw_points = control_points;
    for(int i = 0; i < n_iter; i++) {
        draw_points = generate_points(draw_points);
    }
    glBegin(GL_LINES);
    for(int i = 0; i < draw_points.size()-1; i++) {
        glVertex2f(draw_points.at(i).get_x(), draw_points.at(i).get_y());
        glVertex2f(draw_points.at(i+1).get_x(), draw_points.at(i+1).get_y());
    }
    glEnd();
}

void draw_the_rock(){
    vector<Vertex> head = {
        Vertex(-0.55f, 0.4f),
        Vertex(-0.37f, 0.8f),
        Vertex(0.0f, 0.9f),
        Vertex(0.4f, 0.85f),
        Vertex(0.57f, 0.6f),
        Vertex(0.6f, 0.384f),
        Vertex(0.642f, 0.388f),
        Vertex(0.658f, 0.37f),
        Vertex(0.626f, 0.212f),
        Vertex(0.59f, 0.085f),
        Vertex(0.57f, 0.07f),
        Vertex(0.547f, 0.085f),
        Vertex(0.518f, -0.044f),
        Vertex(0.307f, -0.217f),
        Vertex(0.036f, -0.285f),
        Vertex(-0.202f, -0.25f),
        Vertex(-0.418f, -0.099f),
        Vertex(-0.48f, 0.107f),
        Vertex(-0.507f, 0.08f),
        Vertex(-0.548f, 0.096f),
        Vertex(-0.583f, 0.207f),
        Vertex(-0.605f, 0.413f),
        Vertex(-0.55f, 0.4f)
    };
    draw_curve(head, 10);
    
    vector<Vertex> left_eye = {
        Vertex(-0.302f, 0.44f),
        Vertex(-0.19f, 0.5f),
        Vertex(-0.075f, 0.426f),
        Vertex(-0.19f, 0.405f),
        Vertex(-0.245f, 0.415f),
        Vertex(-0.302f, 0.44f)
    };
    draw_curve(left_eye, 10);
    
    vector<Vertex> left_iris = {
        Vertex(-0.209f, 0.471f),
        Vertex(-0.2176f, 0.43f),
        Vertex(-0.18f, 0.405f),
        Vertex(-0.139f, 0.445f),
        Vertex(-0.14f, 0.465f)

    };
    draw_curve(left_iris, 10);
    
    vector<Vertex> right_eye = {
        Vertex(0.187f, 0.42f),
        Vertex(0.305f, 0.472f),
        Vertex(0.3585f, 0.46f),
        Vertex(0.4075f, 0.416f),
        Vertex(0.302f, 0.39f),
        Vertex(0.187f, 0.42f)
    };
    draw_curve(right_eye, 10);
    
    vector<Vertex> right_iris= {
        Vertex(0.274f, 0.456f),
        Vertex(0.277f, 0.431f),
        Vertex(0.308f, 0.39f),
        Vertex(0.346f, 0.427f),
        Vertex(0.35f, 0.456f)
    };
    draw_curve(right_iris, 10);
    
    vector<Vertex> nose = {
        Vertex(-0.016f, 0.391f),
        Vertex(-0.034f, 0.315f),
        Vertex(-0.088f, 0.255f),
        Vertex(-0.118f, 0.211f),
        Vertex(-0.105f, 0.165f),
        Vertex(-0.064f, 0.152f),
        Vertex(0.171f, 0.152f),
        Vertex(0.22f, 0.171f),
        Vertex(0.225f, 0.209f),
        Vertex(0.205f, 0.249f),
        Vertex(0.153f, 0.293f),
        Vertex(0.1215f, 0.394f)
    };
    draw_curve(nose, 10);
    
    vector<Vertex> left_nostril {
        Vertex(-0.062f, 0.194f),
        Vertex(-0.03f, 0.202f),
        Vertex(0.0025f, 0.1865f),
        Vertex(-0.026f, 0.178f),
        Vertex(-0.062f, 0.194f)
    };
    draw_curve(left_nostril, 5);
    
    vector<Vertex> right_nostril {
        Vertex(0.097f, 0.183f),
        Vertex(0.151f, 0.205f),
        Vertex(0.175f, 0.185f),
        Vertex(0.141f, 0.175f),
        Vertex(0.097f, 0.183f),
    };
    draw_curve(right_nostril, 5);
    
    vector<Vertex> mouth = {
        Vertex(-0.156f, 0.008f),
        Vertex(-0.072f, 0.045f),
        Vertex(-0.0105f, 0.058f),
        Vertex(0.049f, 0.044f),
        Vertex(0.096f, 0.057f),
        Vertex(0.178f, 0.039f),
        Vertex(0.274f, 0.0134f),
        Vertex(0.156f, -0.0395f),
        Vertex(-0.014f, -0.042f),
        Vertex(-0.156f, 0.008f)
    };
    draw_curve(mouth, 10);
    
    vector<Vertex> mouth_line = {
        Vertex(-0.156f, 0.008f),
        Vertex(0.25f, 0.012f)
    };
    draw_curve(mouth_line, 0);
    
    vector<Vertex> left_eyebrow = {
        Vertex(-0.361f, 0.505f),
        Vertex(-0.258f, 0.564f),
        Vertex(-0.108f, 0.555f),
        Vertex(-0.064f, 0.527f),
        Vertex(-0.162f, 0.525f),
        Vertex(-0.256f, 0.532f),
        Vertex(-0.361f, 0.505f)
    };
    draw_curve(left_eyebrow, 8);
    
    vector<Vertex> right_eyebrow = {
        Vertex(0.482f, 0.475f),
        Vertex(0.364f, 0.517f),
        Vertex(0.179f, 0.505f),
        Vertex(0.185f, 0.545f),
        Vertex(0.386f, 0.549f),
        Vertex(0.482f, 0.475f)
    };
    draw_curve(right_eyebrow, 8);
    
    vector<Vertex> laugh_line_left = {
        Vertex(-0.157f, 0.157f),
        Vertex(-0.261f, 0.074f),
        Vertex(-0.276f, -0.02f)
    };
    draw_curve(laugh_line_left, 5);
    
    vector<Vertex> laugh_line_right = {
        Vertex(0.26f, 0.165f),
        Vertex(0.351f, 0.089f),
        Vertex(0.364f, -0.05f)
    };
    draw_curve(laugh_line_right, 5);
    
    vector<Vertex> chin = {
        Vertex(-0.076f, -0.183f),
        Vertex(0.057f, -0.14f),
        Vertex(0.195f, -0.194f)
    };
    draw_curve(chin, 5);
    
    vector<Vertex> earhole_left = {
        Vertex(-0.539f, 0.28f),
        Vertex(-0.555f, 0.225f),
        Vertex(-0.527f, 0.173f)
    };
    draw_curve(earhole_left, 5);
    
    vector<Vertex> earhole_right = {
        Vertex(0.618f, 0.29f),
        Vertex(0.583f, 0.158f),
    };
    draw_curve(earhole_right, 1);
    
    glPointSize(5.0f);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2f(-0.174f, 0.45f);
    glVertex2f(0.312f, 0.438f);
    glEnd();
    
    }

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set our color to black (R, G, B)
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_the_rock();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(600,600); // Set your own window size
    glutCreateWindow("Assignment 1");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

