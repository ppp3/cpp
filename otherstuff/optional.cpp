//Wrapper für nullbare Variable
//Value Semantic
#include <iostream>
#include <string>
#include <optional>

int main()
{
  std::optional<std::string> os{};
  os ="Stefan";
  if (os)
  {
    std:::string s=*os;
  }
  
  if (os.has_value())
  {
    std::string s=*os;
    std::string s2=os.value(); //std::bad_optional_access
    std::string s3=os.value_or("Peter"); //Wenn der Wert null ist, dann gibt Stefab zurück
  }
  
  auto os2=os; //Echte Kopie wird angelegt
  os="Björn";
  std::cout <<"Ergebnis "<<*os<<endl; //Stefan
  
  
  
}
