template <class T>
class coordinate
{
    public:
        T x, y;
};

template <class T>
class figure
{
    protected:
        T area;
        coordinate<T> center;
        std::vector<coordinate<T>> points;
    public:
        virtual void printArea()
        {}

        virtual void printCenter()
        {}

        virtual void printCoord()
        {}
};

template <class T>
class triangle: public figure<T>{
    private:
        std::vector<T> len;
    public:

        triangle(std::vector<coordinate<T>> data)
        {
            figure<T>::points.resize(3);
            figure<T>::points = data;
        }

        void length()
        {
            len.resize(3);
            for (int i = 0; i < 3; i++)
            {
                len[i] = sqrt(pow(abs(figure<T>::points[i].x - figure<T>::points[(i + 1) % 3].x), 2) + pow(abs(figure<T>::points[i].y - figure<T>::points[(i + 1) % 3].y), 2));
            }   
        }

        void areaCalc()
        {
            length();
            T p = (len[0] + len[1] + len[2]) / 2;
            figure<T>::area = sqrt(p * (p - len[0]) * (p - len[1]) * (p - len[2]));
        }

        void centerCalc()
        {
            for(int i = 0; i < figure<T>::points.size(); i++)
            {
                figure<T>::center.x += figure<T>::points[i].x;
                figure<T>::center.y += figure<T>::points[i].y;
            }
            figure<T>::center.x /= figure<T>::points.size();
            figure<T>::center.y /= figure<T>::points.size();
        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << figure<T>::area << std::endl;
        }

        void printCenter()
        {
            centerCalc();
            std::cout << "Center: " << "(" << figure<T>::center.x << ";" << figure<T>::center.y << ")" << std::endl;
        }

        void printCoord()
        {
            for(int i = 0; i < figure<T>::points.size(); i++)
            {
                std::cout << "№" << i + 1 << "(" << figure<T>::points[i].x << ";" << figure<T>::points[i].y << ")" << std::endl;
            }
        }
};

template <class T>
class squary: public figure<T>{
    private:
        T len;
    public:
        squary(coordinate<T> cntr, T length)
        {
            figure<T>::points.resize(1);
            figure<T>::points[0] = cntr;
            len = length;
        }

        void areaCalc()
        {
            figure<T>::area = len * len;
        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << figure<T>::area << std::endl;
        }

        void printCenter()
        {
            std::cout << "Center: " << "(" << figure<T>::points[0].x << ";" << figure<T>::points[0].y << ")" << std::endl;
        }

        void printCoord()
        {
            std::cout << "№1" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№2" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№3" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№4" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y + len / 2 << ")" << std::endl;
        }
};

template <class T>
class angle8: public figure<T>{ //8-ми угольник
    private:
        T len;
    public:

        angle8(coordinate<T> cntr, T length)
        {
            figure<T>::points.resize(1);
            figure<T>::points[0] = cntr;
            len = length;
        }

        void areaCalc() //fixme
        {
            figure<T>::area += figure<T>::points[0].x - len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2 - sin(30 * M_PI / 180);
            figure<T>::area += figure<T>::points[0].x + len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2 - sin(30 * M_PI / 180);
            figure<T>::area += figure<T>::points[0].x + len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2;
            figure<T>::area += figure<T>::points[0].x + len / 2; figure<T>::area -= figure<T>::points[0].y + len / 2;
            figure<T>::area += figure<T>::points[0].x + len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2 + sin(30 * M_PI / 180);
            figure<T>::area += figure<T>::points[0].x - len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2 + sin(30 * M_PI / 180);
            figure<T>::area += figure<T>::points[0].x - len / 2; figure<T>::area -= figure<T>::points[0].y - len / 2;
            figure<T>::area += figure<T>::points[0].x - len / 2; figure<T>::area -= figure<T>::points[0].y + len / 2;

        }

        void printArea()
        {
            areaCalc();
            std::cout << "S = " << figure<T>::area << std::endl;
        }

        void printCenter()
        {
            std::cout << "Center: " << "(" << figure<T>::points[0].x << ";" << figure<T>::points[0].y << ")" << std::endl;
        }

        void printCoord()
        {
            std::cout << "№1" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y - len / 2 - 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№2" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y - len / 2 - 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№3" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y - len / 2 << ")" << std::endl;
            std::cout << "№4" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№5" << "(" << figure<T>::points[0].x + len / 2 << ";" << figure<T>::points[0].y + len / 2 + 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№6" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y + len / 2 + 5*tan(30 * M_PI / 180) << ")" << std::endl;
            std::cout << "№7" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y + len / 2 << ")" << std::endl;
            std::cout << "№8" << "(" << figure<T>::points[0].x - len / 2 << ";" << figure<T>::points[0].y - len / 2 << ")" << std::endl;
        }
};