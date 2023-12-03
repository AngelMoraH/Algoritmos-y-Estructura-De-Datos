#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;

class Jockey
{
public:
    Jockey(const string &name, int experience) : name(name), experience(experience) {}

    const string &getName() const
    {
        return name;
    }

    int getExperience() const
    {
        return experience;
    }

private:
    string name;
    int experience;
};

class Horse
{
public:
    Horse(const string &name, const Jockey &jockey) : name(name), steps(0), jockey(jockey) {}

    const string &getName() const
    {
        return name;
    }

    int getSteps() const
    {
        return steps;
    }

    void advance(double probability)
    {
        // Avanza el caballo según la probabilidad recibida
        if (probability > 0.8)
            steps += 5;
        else if (probability > 0.3)
            steps += 3;
        else
            steps += 1;
    }

    const Jockey &getJockey() const
    {
        return jockey;
    }

private:
    string name;
    int steps;
    Jockey jockey;
};

// Función de comparación para ordenar los caballos por la cantidad de pasos
bool comparar(const Horse &a, const Horse &b)
{
    return a.getSteps() < b.getSteps();
}

int main()
{
    // Crear objetos Jockey para los jinetes
    vector<Jockey> jockeys = {
        Jockey("Jockey 1", 3),
        Jockey("Jockey 2", 5),
        Jockey("Jockey 3", 2),
        Jockey("Jockey 4", 4),
        Jockey("Jockey 5", 1),
        Jockey("Jockey 6", 3),
        Jockey("Jockey 7", 5),
        Jockey("Jockey 8", 2),
        Jockey("Jockey 9", 4),
        Jockey("Jockey 10", 1)};

    // Crear objetos Horse para los caballos, asignando un jinete a cada uno
    vector<Horse> horses = {
        Horse("Uno", jockeys[0]),
        Horse("Dos", jockeys[1]),
        Horse("Tres", jockeys[2]),
        Horse("Cuatro", jockeys[3]),
        Horse("Cinco", jockeys[4]),
        Horse("Seis", jockeys[5]),
        Horse("Siete", jockeys[6]),
        Horse("Ocho", jockeys[7]),
        Horse("Nueve", jockeys[8]),
        Horse("Diez", jockeys[9])};

    // Configurar generador de números aleatorios
    random_device rd;
    default_random_engine engine(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    int targetDistance = 1000; // Distancia objetivo de la carrera
    bool raceFinished = false; // Indica si la carrera ha terminado

    // Simulación de la carrera
    while (!raceFinished)
    {
        // Avanzar cada caballo y verificar si ha alcanzado la distancia objetivo
        for (auto &horse : horses)
        {
            double probability = dist(engine); // Generar una probabilidad aleatoria
            horse.advance(probability);        // Avanzar el caballo según la probabilidad generada
            if (horse.getSteps() >= targetDistance)
                raceFinished = true; // Si el caballo ha alcanzado o superado la distancia objetivo, se marca la carrera como terminada
        }
    }

    // Ordenar los caballos por la cantidad de pasos realizados
    sort(horses.begin(), horses.end(), comparar);

    // Mostrar los resultados de la carrera
    cout << "Ganador: " << horses[0].getName() << ", cantidad de pasos: " << horses[0].getSteps() << ", Jockey: " << horses[0].getJockey().getName() << ", Experiencia del Jockey: " << horses[0].getJockey().getExperience() << endl;
    cout << "2do puesto: " << horses[1].getName() << ", cantidad de pasos: " << horses[1].getSteps() << ", Jockey: " << horses[1].getJockey().getName() << ", Experiencia del Jockey: " << horses[1].getJockey().getExperience() << endl;
    cout << "3er puesto: " << horses[2].getName() << ", cantidad de pasos: " << horses[2].getSteps() << ", Jockey: " << horses[2].getJockey().getName() << ", Experiencia del Jockey: " << horses[2].getJockey().getExperience() << endl;

    return 0;
}
