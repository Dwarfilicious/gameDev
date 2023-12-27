/* Author: Bas Zoeteman
 * Date of Initial Creation: 26-12-2023
 * Class data for a square. */

#ifndef SQUARE_H
#define SQUARE_H

class Square
{
    public:
        Square(float x, float y, float size, float red, float green, float blue);
        float getX() const;
        float getY() const;
        float getSize() const;
        float getRed() const;
        float getGreen() const;
        float getBlue() const;
        void setX(float x);
        void setY(float y);
        void setSize(float size);
        void setRed(float red);
        void setGreen(float green);
        void setBlue(float blue);
        void drawSquare() const;
    private:
        float x;
        float y;
        float size;
        float red;
        float green;
        float blue;
};

#endif /* SQUARE_H */
