#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    // Capturar una imagen de la pantalla
    Mat screenshot;
    cv::VideoCapture cap(0);
    cap >> screenshot;

    // Crear una ventana para mostrar la imagen capturada
    namedWindow("Pantalla", WINDOW_NORMAL);

    // Mostrar la imagen capturada en la ventana
    imshow("Pantalla", screenshot);

    // Esperar a que el usuario presione una tecla
    waitKey(0);

    // Analizar los píxeles de la imagen capturada utilizando OpenCV
    // ...

    return 0;
}

