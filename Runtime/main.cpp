#include "Application.h"

int main(){

    Application app;
    app.Run();
    return 0;

}

//Oui, c’est encore le même type de souci : le cache CMake a été créé avec une autre plateforme (souvent Win32) et maintenant Visual Studio ou CMake essaie d’utiliser x64.
//
//Le plus propre est de repartir d’un dossier de build neuf.
//
//Fais ça
//
//Ferme Visual Studio.
//
//Ensuite dans PowerShell, à la racine du projet :
//
//Remove - Item - Recurse - Force build
//Remove - Item - Recurse - Force build - x64
//
//Si un des deux dossiers n’existe pas, ce n’est pas grave.
//
//Puis recrée un seul dossier de build en x64 :
//
//     cmake - S . - B build - x64 - G "Visual Studio 17 2022" - A x64
//
//Puis compile :
//
//     cmake --build build - x64 --config Debug



//Visual Studio te dit simplement :
//
//"Le cache CMake est obsolète, il faut le regénérer."
//
//Solution terminal(si tu préfères)
//
//Dans ton dossier projet :
//
//     cmake --fresh - S . - B build - x64
//
//ou plus simple :
//
//     cmake - S . - B build - x64
// 
// 
//Si Visual Studio bug encore
//
//Supprime juste le dossier de build :
//
//      Remove - Item - Recurse - Force build - x64
//
//puis :
//
//      cmake - S . - B build - x64 - G "Visual Studio 17 2022" - A x64