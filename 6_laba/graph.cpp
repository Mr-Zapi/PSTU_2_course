#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;

class Figura
{
public:
    Figura(double p_x = 0, double p_y = 0, double p_size = 0, int polig = 30, Color p_color = Color::White)
    {
        if (p_color == Color::White)
        {
            color = Color(rand() % 256, rand() % 256, rand() % 256);
        }
        else
        {
            color = p_color;
        }
        
        x = p_x;
        y = p_y;
        size = p_size;
        fig = CircleShape(size, polig);
        fig.setFillColor(color);
        fig.setPosition(x, y);
    }

    void move(double dx, double dy)
    {
        fig.move(dx, dy);
    }
    void krug(){
        angle += 0.01;
        dx = x + 30 * std::cos(angle);
        dy = y + 30 * std::sin(angle);
        fig.setPosition(dx, dy);
    }
    CircleShape fig;
private:
    double angle = 0;
    double x, y, dx, dy;
    double size;
    Color color;
};

class Circle : public Figura
{
public:
    Circle(double p_x, double p_y, double p_size, int polig, Color p_color = Color::White)
    : Figura(p_x, p_y, p_size, polig, p_color) {}

    void draw(RenderWindow &window){
        window.draw(fig);
    }
};

class Triangle : public Figura
{
public:
    Triangle(double p_x, double p_y, double p_size, int polig, Color p_color = Color::White)
    : Figura(p_x, p_y, p_size, polig, p_color) {}

    void draw(RenderWindow &window){
        window.draw(fig);
    }
};

class Line
{
public:
    Line(double p_x, double p_y, double p_length = 0, double p_width = 0, int p_corner = 0){
        x = p_x;
        y = p_y;
        length = p_length;
        width = p_width;
        corner = p_corner;
        rectangle = sf::RectangleShape(sf::Vector2f(length, width));    
        rectangle.setPosition(x, y);
        rectangle.rotate(corner);
        rectangle.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
    }
    sf::RectangleShape rectangle;
    void move(double dx, double dy)
    {
        rectangle.move(dx, dy);
    }
    void rot(){
        rectangle.rotate(0.1);
    }
    void draw(RenderWindow &window){
        window.draw(rectangle);
    }

private:
    double length, width, x, y;
    double corner;
};
class Me
{
public:
    Me(double x, double y) {
        // М
        lines.push_back(Line(x, y, 3, 40));
        lines.push_back(Line(x + 30, y, 3, 40));
        lines.push_back(Line(x, y, 25, 3, 45));
        lines.push_back(Line(x + 30, y, 3, 25, 45));

        // П
        lines.push_back(Line(x + 40, y, 30, 3));   
        lines.push_back(Line(x + 40, y, 40, 3, 90));  
        lines.push_back(Line(x + 70, y, 40, 3, 90)); 
    }

    void draw(RenderWindow &window) {
        for (auto &line : lines) {
            line.draw(window);
        }
    }
    void move(double xi, double yi){
        for (auto &line : lines) {
            line.move(xi, yi);
        }
    }

private:
    std::vector<Line> lines;
};
int main()
{
    srand(time(NULL));
    double xi, yi;
    RenderWindow window(VideoMode(1920, 1080), "6_laba");
    std::vector<Circle> circles;
    std::vector<Triangle> triangles; 
    std::vector<Line> lines;
    std::vector<Me> me_;
    while (window.isOpen())
    {
        Event event;
        double len, wid, x, y, r;
        int corner;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::F1:
                    {
                        x = rand() % 1980;
                        y = rand() % 1000;
                        r = rand() % 100;
                        Circle c(x, y, r, 30); 
                        circles.push_back(c);
                        break;
                    }
                    case Keyboard::F2:
                    {
                        x = rand() % 1980;
                        y = rand() % 1000;
                        r = rand() % 100;
                        Triangle t(x, y, r, 3);
                        triangles.push_back(t);
                        break;
                    }
                    case Keyboard::F3:
                        x = rand() % 1980;
                        y = rand() % 1000;
                        len = rand() % 1000;
                        wid = rand() % 100;
                        corner = rand() % 100;
                        lines.push_back(Line(x, y, len, wid, corner));
                        break;
                    case Keyboard::C:
                        circles = {};
                        triangles = {};
                        lines = {};
                        window.clear();
                        break;
                    case Keyboard::F4:
                    {
                        x = rand() % 1980;
                        y = rand() % 1000;
                        r = 1;
                        Circle c(x, y, r, 30); 
                        circles.push_back(c);
                        break
                        ;
                    }
                    case Keyboard::F5:
                    {
                        x = rand() % 1980;
                        y = rand() % 1000;
                        Me m(x, y); 
                        me_.push_back(m);
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        
        window.clear();
        for (auto &triangle : triangles)
        {
            triangle.move((double)(rand())/RAND_MAX * 3 - 1.5, (double)(rand())/RAND_MAX * 3 - 1.5);
            triangle.draw(window); 
        }
        for (auto &circle : circles)
        {
            circle.krug();
            circle.draw(window);
        }
        for (auto &line : lines)
        {
            line.move((double)(rand())/RAND_MAX, (double)(rand())/RAND_MAX * 3 - 1.5);
            line.rot();
            line.draw(window);
        }
        for (auto &me : me_)
        {
            me.move(0, -0.05);
            me.draw(window);
        }
        window.display();
    }

    return 0;
}
