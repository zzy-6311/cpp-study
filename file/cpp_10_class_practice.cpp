#include<iostream>

class cube{
private:
    double m_h;
    double m_l;
    double m_w;

public:
    void set_h(double h){
        m_h = h;
    }

    void set_l(double l){
        m_l = l;
    }

    void set_w(double w){
        m_w = w;
    }

    double get_h(){
        return m_h;
    }

    double get_l(){
        return m_l;
    }

    double get_w(){
        return m_w;
    }

    double s(){
        return (m_h * m_l + m_h * m_w + m_l * m_w) * 2;
    }

    double v(){
        return m_l * m_w * m_h;
    }
};

double math_s(double h, double l, double w){
    return (h * l + h * w + l * w) * 2;
}

double math_v(double h, double l, double w){
    return h * l * w;
}

int main(void){
    double h = 5, l = 10, w = 15;
    cube c1;
    c1.set_h(h);
    c1.set_l(l);
    c1.set_w(w);

    if (math_s(h, l, w) == c1.s() && math_v(h, l, w) == c1.v() && h == c1.get_h() && l == c1.get_l() && w == c1.get_w()){
        std::cout << "相同" << std::endl;
    }
    else{
        std::cout << "不相同" << std::endl;
    }
}