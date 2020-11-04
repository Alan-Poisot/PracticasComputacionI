#ifndef PUNTO_H
#define PUNTO_H


class Punto2D
{
    public:

        void SetPosicion(float a, float b);
        void Trasladar(float a, float b);
        void RotarRespectoAlOrigen(float a);
        void Escalar(float a, float b);


        float GetX();
        float GetY();

    protected:
    private:
        float x=0,y=0;
};

#endif
