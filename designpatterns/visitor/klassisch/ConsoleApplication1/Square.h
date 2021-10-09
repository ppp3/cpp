#pragma once;
class Square : public Shape
{
    public:
        explicit Square(double side):Shape(), side_(side)
        {}
        
        void accept(const Visitor& v) override 
        {
            v.visit(*this);
        }
        
        
        double side() const {
            return side_;
            
        }
    
    private:
        double side_;
        
};
