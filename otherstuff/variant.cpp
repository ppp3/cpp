#include <variant>

struct Print
{
    void operator()(int i) const {
        std::cout << "int: i=" << i << "\n";
    }

    void operator()(double d) const {
        std::cout <<"double: d = " << d << "\n";
    }

    void operator()(std::string s) const {
        std::cout << "String: s = " << s << "\n";
    }

};
int main()
{
    std::variant<int, double, std::string> v{};
    v = 42;
    v = 3.1;
    v = "dsfdfd";
    v = 43;
    try
    {
        int i = std::get<int>(v); //std::bad_variant_access
    }
    catch (const std::bad_variant_access& e)
    {
        cout << "Geht nicht\n";
    }
    int* i_p = std::get_if<int>(&v); //Gibt nullptr zurück
    bool has_int = std::holds_alternative<int>(v); //false
    std::visit(Print(), v);

    //v ist ein int
    auto v2 = v;
    v = "long string";
    std::visit(Print(), v);
    std::visit(Print(), v2);


    return 0;
}
