/* Author: Bas Zoeteman
 * Date of Initial Creation: 27-12-2023
 * The color class, which represents a color in the RGB color space. */

#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color(float r, float g, float b);
    float getR() const;
    float getG() const;
    float getB() const;
    void setR(float r);
    void setG(float g);
    void setB(float b);

private:
    float r, g, b;
};

#endif /* COLOR_H */
