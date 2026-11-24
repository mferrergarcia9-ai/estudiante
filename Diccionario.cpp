//editado por monica

#include "diccionario.h"

template <class T, class U>
void Diccionario<T,U> :: Copiar(const Diccionario<T, U>& D){
    datos = D.datos;    // Porque lista ya tiene el operador =
}

template <class T, class U>
void Diccionario<T,U> :: Borrar(){
    datos.clear();
}

template <class T, class U>
Diccionario<T,U> :: Diccionario(){
    // SE queda vacio, no lo tengo que hacer de forma manual, porque la lista ya lo tiene
}

template <class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario<T,U> &D) {
    Copiar(D);
}

template <class T, class U>
Diccionario<T,U>::~Diccionario(){
    Borra();
} 

template <class T, class U>
Diccionario<T, U> & Diccionario<T,U>::operator=(const Diccionario<T, U> &D){
    datos = D.datos;
    return *this;
}

template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out){
    bool encontrada = false;
    auto it = datos.begin;
    while(it != datos.end() && it->first < p){
        it++;
    }

    it_out = it;
    if(it != datos.end() && it->first == p){
        encontrada = true;       
    }

    return encontrada;
}

template <class T, class U>
void Diccionario<T,U>::Insertar(const T& clave, const list<U> &info){
    typename Diccionario<T,U>::iterator it;

    bool esta = Esta_Clave(clave, it);
    if(!esta){
        datos.insert(it, {clave,info});
    }
}

template <class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s, const T &p){
    typename Diccionario<T,U>::iterator it;

    bool esta = Esta_Clave(p, it);
    if(!esta){
        data<T,U> nuevo;
        nuevo.first = p;
        nuevo.second.push_back(s);

        datos.insert(it, nuevo);
    }

    else {
        it->second.push_back(s);
    }
}

template <class T, class U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p){
    typename Diccionario<T,U>::iterator it;

    bool esta = Esta_Clave(p,it);
    if(esta){
        return it->second;
    }
    else
        return  list<U>();
}

template <class T, class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template <class T, class U>
bool  Diccionario<T,U>::Borrar(const T & c){
    typename Diccionario<T,U>::iterator it;

    bool esta = Esta_Clave(c,it);
    if(esta){
        datos.erase(it);
    }

    return esta;
}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::union_d(const Diccionario &D){
    Diccionario<T,U> res(*this); //aqui creamos una copia del diccionario para no estropear el original
    for(typename list<data<T,U> >::const_iterator itD = D.datos.begin(); itD != D.datos.end(); ++itD){  //recorre ficha por ficha el diccionario D
        typename Diccionario<T,U>::iterator pos;
     
   

}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::diferencia(const Diccionario &D){
    Diccionario<T,U> res(*this);
    for(typename list<data<T,U> >::const_iterator itD = D.datos.begin(); itD != D.datos.end(); ++itD){
        res.Borrar(itD->clave); //borra de res la fichas enteras clave e info si  la clave aparece en D la borra en res, D no s epuede borarr es const
    }
    return res;

}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::interseccion(const Diccionario &D){

}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::Devolver_rango(const T &i, const T &f){

}


