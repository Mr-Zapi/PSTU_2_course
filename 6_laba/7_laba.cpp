#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;


class c_text {
public:
    c_text(const std::string& fontPath, const std::string& initialText) {
        font.loadFromFile(fontPath);
        text.setFont(font);
        text.setString(initialText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 100);
    }

    void setString(const std::string& newText) {
        text.setString(newText);
    }

    void setPosition(float x, float y) {
        text.setPosition(x, y);
    }

    void draw(RenderWindow& window) {
        window.draw(text);
    }

private:
    Font font;
    Text text;
};
class Figura
{
public:
    Figura(double p_x = 0, double p_y = 0, double p_size = 0, int polig = 30, Color p_color = Color::White)
    {
        if (p_color == Color::White)
        {
            color = Color(rand() % 256, rand() % 256, rand() % 256, 255);
        }
        else
        {
            color = p_color;
        }
        
        x = p_x;
        y = p_y;
        size = p_size;
        fig = CircleShape(size, polig);
        fig.setFillColor(Color::Black);
        fig.setPosition(x, y);
        fig.setOutlineThickness(10.f);
        fig.setOutlineColor(color); 
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
    sf::Vector2f get(){
        return fig.getPosition();
    }
    CircleShape fig;
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
    double length, width, x, y;
    double corner;
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

class Aim : public Figura {
public:
    Line l1, l2;
    Circle circle;
    int shag = 7;
    double x, y, size;
    Aim(double p_x, double p_y, double p_size, int polig, Color p_color = Color::White)
    : Figura(p_x, p_y, p_size, polig, p_color), 
      l1(p_x, p_y + p_size, p_size * 2, 3), 
      l2(p_x + p_size, p_y, p_size * 2, 3, 90),
      x(p_x), 
      y(p_y), 
      size(p_size),
      circle(p_x, p_y, p_size, polig, p_color){
    }
    void up(){
        l1.move(0, -shag);
        l2.move(0, -shag);
        circle.move(0, -shag);
    }
    void down(){
        l1.move(0, shag);
        l2.move(0, shag);
        circle.move(0, shag);
    }
    void left(){
        l1.move(-shag, 0);
        l2.move(-shag, 0);
        circle.move(-shag, 0);
    }
    void right(){
        l1.move(shag, 0);
        l2.move(shag, 0);
        circle.move(shag, 0);
    }
    void draw(RenderWindow &window){
        circle.draw(window);
        l1.draw(window);
        l2.draw(window);
    }
};
bool check(sf::Vector2f h_c, sf::Vector2f h_t, double r){
    double xc = h_c.x;
    double yc = h_c.y;
    double xt = h_t.x;
    double yt = h_t.y;
    if (fabs(xt - xc) < r && fabs(yt - yc) < r){;
        return true;
    }
    return false;
}
int main()
{
    
    srand(time(NULL));
    double xi, yi;
    RenderWindow window(VideoMode(1920, 1080), "6_laba");
    std::vector<Circle> circles;
    std::vector<Triangle> triangles; 
    std::vector<Line> lines;
    c_text text_aim_x("arial.ttf", std::to_string(0));
    c_text text_aim_y("arial.ttf", std::to_string(0));
    c_text text_tri_x("arial.ttf", std::to_string(0));
    c_text text_tri_y("arial.ttf", std::to_string(0));
    text_tri_x.setPosition(100, 200);
    text_tri_y.setPosition(300, 200);
    text_aim_y.setPosition(300, 100);
    Aim aim(1920 / 2, 1080 / 2, 40, 30, Color::Green);
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
                    case Keyboard::C:
                        circles = {};
                        triangles = {};
                        lines = {};
                        window.clear();
                        break;
                    case Keyboard::Up:
                    {
                        aim.up();
                        break;
                    }
                    case Keyboard::Down:
                    {
                       aim.down();
                       break;
                    }
                    case Keyboard::Left:
                    {
                       aim.left();
                       break;
                    }
                    case Keyboard::Right:
                    {
                       aim.right();
                       break;
                    }
                    default:
                        break;
                }
            }
        }
        
        window.clear();
        for (size_t i = 0; i < triangles.size();) {
            triangles[i].move((double)(rand()) / RAND_MAX * 3 - 1.5, (double)(rand()) / RAND_MAX * 3 - 1.5);
            text_aim_x.setString(std::to_string(aim.circle.get().x));
            text_tri_x.setString(std::to_string(triangles[i].get().x));
            text_aim_y.setString(std::to_string(aim.circle.get().y));
            text_tri_y.setString(std::to_string(triangles[i].get().y));
            if (check(aim.circle.get(), triangles[i].get(), triangles[i].size)) {
                triangles.erase(triangles.begin() + i);
                continue; 
            }
            triangles[i].draw(window);
            i++;    
        }
        for (size_t i = 0; i < circles.size();) {
            circles[i].krug();
            text_aim_x.setString(std::to_string(aim.circle.get().x));
            text_tri_x.setString(std::to_string(circles[i].get().x));
            text_aim_y.setString(std::to_string(aim.circle.get().y));
            text_tri_y.setString(std::to_string(circles[i].get().y));
            if (check(aim.circle.get(), circles[i].get(), circles[i].size)) {
                circles.erase(circles.begin() + i);
                continue; 
            }
            circles[i].draw(window);
            i++;    
        }
        aim.draw(window);
        text_aim_x.draw(window);
        text_tri_x.draw(window);
        text_aim_y.draw(window);
        text_tri_y.draw(window);
        window.display();
    }

    return 0;
}
