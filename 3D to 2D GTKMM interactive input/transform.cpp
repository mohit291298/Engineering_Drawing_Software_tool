#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

vector<co_ordinates_3D> transform(vector<co_ordinates_3D> graph){
	float translation[4][4] = {};
	float rotationx[4][4] = {};
	float rotationy[4][4] = {};
	float rotationz[4][4] = {};
	float temp1[4][4] = {};
	float temp2[4][4] = {};
	float tempf[4][4] = {};
	float a,b,c;
	float s1,s2,s3;
	float theta_x,theta_y,theta_z;
	float ctheta_x,ctheta_y,ctheta_z;
	float stheta_x,stheta_y,stheta_z;
	cout << "Enter the shift amount in x-coordinate : ";
	cin >> a ;
	cout << "Enter the shift amount in y-coordinate : ";
	cin >> b ;
	cout << "Enter the shift amount in z-coordinate : ";
	cin >> c ;
	cout << "Enter the rotation angle about x-axis :";
	cin >> theta_x;
	cout << "Enter the rotation angle about y-axis :";
	cin >> theta_y;
	cout << "Enter the rotation angle about z-axis :";
	cin >> theta_z;
	cout << "Enter the scaling factor for x-coordinate :";
	cin >> s1;
	cout << "Enter the scaling factor for y-coordinate :";
	cin >> s2;
	cout << "Enter the scaling factor for z-coordinate :";
	cin >> s3;
	translation[0][0] = 1;
	translation[1][1] = 1;
	translation[2][2] = 1;
	translation[3][3] = 1;
	translation[0][3] = a;
	translation[1][3] = b;
	translation[2][3] = c;
	theta_x = (theta_x*PI)/180.0;
	theta_y = (theta_y*PI)/180.0;
	theta_z = (theta_z*PI)/180.0;
	ctheta_x = cos(theta_x);
	ctheta_y = cos(theta_y);
	ctheta_z = cos(theta_z);
	stheta_x = sin(theta_x);
	stheta_y = sin(theta_y);
	stheta_z = sin(theta_z);
	rotationx[0][0] = 1;
	rotationx[3][3] = 1;
	rotationx[1][1] = ctheta_x;
	rotationx[2][2] = ctheta_x;
	rotationx[1][2] = stheta_x;
	rotationx[2][1] = -1*stheta_x;
	rotationy[0][0] = ctheta_y;
	rotationy[1][1] = 1;
	rotationy[2][2] = ctheta_y;
	rotationy[3][3] = 1;
	rotationy[0][2] = -1*stheta_y;
	rotationy[2][0] = stheta_y;
	rotationz[0][0] = ctheta_z;
	rotationz[1][1] = ctheta_z;
	rotationz[2][2] = 1;
	rotationz[3][3] = 1;
	rotationz[0][1] = stheta_z;
	rotationz[1][0] = -1*stheta_z;
	for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                temp1[i][j] += translation[i][k]*rotationx[k][j];
                temp2[i][j] += rotationy[i][k]*rotationz[k][j];
            }
        }
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                tempf[i][j] += temp1[i][k]*temp2[k][j];
            }
        }
    }
    for(int i=0; i < graph.size();i++){
    	float cof[4] = {};
    	float x = graph.at(i).x;
    	float y = graph.at(i).y;
    	float z = graph.at(i).z;
    	float mat[4] = {x,y,z,-1};
    	for (int j = 0; j < 4; j++){
           	for (int k = 0; k < 4; k++){
               	cof[j] += tempf[j][k]*mat[k];
            }
    	}
    	graph.at(i).x = cof[0]*s1;
    	graph.at(i).y = cof[1]*s2;
    	graph.at(i).z = cof[2]*s3;
    }
    return graph;
}