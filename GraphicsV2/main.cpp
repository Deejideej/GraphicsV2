#include <iostream>
#include <vector>


void printWindow (int plane[100][100]) {
    for(size_t y = 0; y < 100; y++) {
        char line[200];
        for(size_t x = 0; x < 100; x++) {
            if(plane[x][y] == 1) {
                line[x * 2] = '0';
                line[x * 2 - 1] = '0';
            } else {
                line[x * 2] = ' ';
                line[x * 2 - 1] = ' ';
            }
        }
        std::cout << line << std::endl;
    }
}

class vertex {
public:
    std::vector<float> localPosition {0, 0, 0}; // x, y, z
    vertex (float x, float y, float z);
    // This function will return the x and y as they would be projected on the window
    int x(float d) {return (d/localPosition[2])*localPosition[0];}
    int y(float d) {return (d/localPosition[2])*localPosition[1];}
};

vertex::vertex(float x, float y, float z) {
    localPosition[0] = x; localPosition[1] = y; localPosition[2] = z;
}

int main()
{
    // Set some variables
    // d corresponds to the view window that the projection is drawn to, changing it will change the distance between the window and the camera object
    float d = 10;

    // Create a vector to hold each vertex, make this list for objects when you figure it out lol
    std::vector<vertex> renderList;

    // Create a vertex, add it to the list we created earlier
    vertex dot0(50, 50, 50);
    renderList.push_back(dot0);
    vertex dot1(80, 50, 50);
    renderList.push_back(dot1);
    vertex dot2(50, 50, 80);
    renderList.push_back(dot2);
    vertex dot3(80, 50, 80);
    renderList.push_back(dot3);

    vertex dot4(50, 80, 50);
    renderList.push_back(dot4);
    vertex dot5(80, 80, 50);
    renderList.push_back(dot5);
    vertex dot6(50, 80, 80);
    renderList.push_back(dot6);
    vertex dot7(80, 80, 80);
    renderList.push_back(dot7);

    // Create an array to hold the value of each pixel on screen, note that if you would like to change the resolution it is neccesary to update the print function
    int window[100][100] = {{false}}; // x, y
    while (true) {
        for(size_t y = 0; y < 100; y++) {
            for(size_t x = 0; x < 100; x++) {
                window[x][y] = false;
            }
        }
        // Add each vertex to the window
        for (size_t i = 0; i < renderList.size(); i++){
            window[renderList[i].x(d) + 50][renderList[i].y(d) + 50] = 1;
            renderList[i].localPosition[2]--;
        }

        printWindow(window);
        _sleep(5);
        system("cls");
    }
    return 0;
}

/*
std::vector<std::vector<float>> initialiseMatrix(unsigned height, unsigned width) {
    return std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}*/


