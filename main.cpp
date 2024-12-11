#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <random>

//TASK 2 function
std::vector<std::shared_ptr<Curve>> populateCurves() {
    std::vector<std::shared_ptr<Curve>> curves;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distr(0.1, 20.0);
    std::uniform_int_distribution<int> distrType(0, 2);
    std::uniform_int_distribution<unsigned int> distrCount(0, 1000);
    unsigned int count = distrCount(gen);

    curves.reserve(count);
    for (unsigned int i = 0; i < count; ++i) {
        int type = distrType(gen);
        switch (type){
        case 0:
        {
            double r = distr(gen);
            curves.push_back(std::make_shared<Circle>(r));
            break;
        }
        case 1:
        {
            double rX = distr(gen);
            double rY = distr(gen);
            curves.push_back(std::make_shared<Ellipse>(rX,rY));
            break;
        }
        case 2:
        {
            double r = distr(gen);
            double s = distr(gen);
            curves.push_back(std::make_shared<Helix>(r,s));
            break;
        }
        }
    }
    return curves;
}

//TASK 3 function
void printCurvesInfo(const std::vector<std::shared_ptr<Curve>>& curves) {
    const double t = M_PI_4;
    for (const auto& curve : curves) {
        Point3D point = curve->getPoint(t);
        Point3D derivative = curve->getDerivative(t);
        std::cout << "Point: " << "(" << point.x << ", " << point.y << ", " << point.z << ")\n";
        std::cout << "Derivative: " << "(" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
    }
}

//TASK 4 function
std::vector<std::shared_ptr<Circle>> extractCircles(const std::vector<std::shared_ptr<Curve>>& curves) {
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }
    return circles;
}

//TASK 5 function
void sortCirclesByRadius(std::vector<std::shared_ptr<Circle>>& circles) {
    std::sort(circles.begin(), circles.end(), [](const auto& c1, const auto& c2) {
        return c1->getRadius() < c2->getRadius();
    });
}

//TASK 6 function
double computeTotalRadiusSum(const std::vector<std::shared_ptr<Circle>>& circles) {
    double totalSum = 0.0;
    for (const auto& circle : circles) {
        totalSum += circle->getRadius();
    }
    return totalSum;
}

int main() {
    auto curves = populateCurves();
    std::cout << "Container was populated by curves with random parameters" << std::endl;
    std::cout << "________________________________________" << std::endl;

    std::cout << "Curves info at t = PI/4:\n";
    printCurvesInfo(curves);
    std::cout << "________________________________________" << std::endl;

    auto circles = extractCircles(curves);
    std::cout << "Circles was extracted from first container" << std::endl;
    std::cout << "________________________________________" << std::endl;
    sortCirclesByRadius(circles);
    std::cout << "Circles was sorted in second container" << std::endl;
    std::cout << "________________________________________" << std::endl;

    std::cout << "\nSorted circles by radius:\n";
    for (const auto& circle : circles) {
        std::cout << "Radius: " << circle->getRadius() << "\n";
    }
    std::cout << "________________________________________" << std::endl;

    double totalRadiusSum = computeTotalRadiusSum(circles);
    std::cout << "\nTotal sum of radii: " << totalRadiusSum << "\n";
    std::cout << "________________________________________" << std::endl;

    return 0;
}