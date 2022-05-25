#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;


class Juego{
    private:
        Juego() = default;
        static Juego iniciar;
        void Compitiendo(int veracidad)const{
            unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
            std::default_random_engine e(seed);
            std::uniform_int_distribution<int>distribution(1,100);
            vector<int> vec;
            int n = 0;
            int n_random;
            int limite = -1;
            if(veracidad == 0 || veracidad == 1)
                limite = 5;
            else if(veracidad == 2)
                limite = 1;
            else if(veracidad == 3)
                limite = 3;
            else if(veracidad == 4)
                limite = 2;
            while(n <limite){
                n_random = distribution(e);
                if(std::find(vec.begin(),vec.end(),n_random) == vec.end() && (n_random % 2 == 0 && veracidad == 0 || n_random % 2 != 0 && veracidad==1 ||esPrimo(n_random) && veracidad ==2 ||  esMultiplo10(n_random) && veracidad == 3 || esMultiplo25(n_random) && veracidad == 4)){
                        n++;
                        vec.push_back(n_random);
                }
            }
        }
        bool esPrimo(int n)const{
            int cont = 0;
            for(int i = 1; i <=n;i++){
                if(n % i == 0)
                    cont++;
            }
            if(cont == 2)
                return true;
            else
                return false;
        }
        bool esMultiplo10(int n)const{
            if(n % 10 == 0)
                return true;
            else 
                return false;
        }

        bool esMultiplo25(int n)const{
            if(n % 25 ==0)
                return true;
            else
                return false;
        }
        
    public:
        Juego(const Juego&) = delete;
        static Juego&Get()
        {
            return iniciar;
        }
        void IniciarJuego(const string& estrategia)const{
            if(estrategia == "Pares")
                Compitiendo(0);
            else if(estrategia == "Impares")
                Compitiendo(1);
            else if(estrategia == "Un primo")
                Compitiendo(2);
            else if(estrategia == "Multiplos 10")
                Compitiendo(3);
            else if(estrategia == "Multiplos 25")
                Compitiendo(4);
                
        }
};


Juego Juego::iniciar;

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Juego::Get().IniciarJuego("Pares");
    cout << "Termino estrategia Pares\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Juego::Get().IniciarJuego("Impares");
    cout << "Termino estrategia Impares\n";

}

void ThreadAlfa(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Juego::Get().IniciarJuego("Un primo");
    cout << "Termino estrategia Primo\n";

}

void ThreadOmega(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Juego::Get().IniciarJuego("Multiplos 10");
    cout << "Termino estrategia Multiplos de 10\n";

}
void ThreadTauro(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Juego::Get().IniciarJuego("Multiplos 25");
    cout << "Termino estrategia Multiplos de 25\n";

}




int main()
{
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    std::thread t3(ThreadAlfa);
    std::thread t4(ThreadOmega);
    std::thread t5(ThreadTauro);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}