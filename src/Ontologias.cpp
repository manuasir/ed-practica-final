
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

bool Ontologias::lee_significados(const char * fich_sig){
  ifstream flujo (fich_sig);
  string line;
  while (getline(flujo, line)) {
    string index = line;
    const char * cstr = line.c_str();
    //cout << "una linea:" << index << '\n';
    int i;
    for(i=0 ; i<int(line.size()) and cstr[i] != ' ';i++);
    int key = stoi(line.substr(0,i));
    string significado = line.substr(i,line.size());
    //cout << "una key " << key << '\n';
    //cout << "un sign" << significado << '\n';
    significados[key] = significado;
  }
  return true;
}

bool Ontologias::Escribe(const char * fich_jerarquia,const char * fic_significados){
  ofstream os;
  os.open("salidaSignificados.txt");
  map<int,string>::iterator ite;
  for(ite=significados.begin();ite!=significados.end();++ite) {
    os<<(*ite).first;
    os<<" ";
    os<<(*ite).second;
    os<<'\n';
  }
  os.close();
  os.open("salidaArbol.txt");
  os<<ab;
  os.close();
  return true;
}


bool Ontologias::Lee(const char * fich_jerarquia,const char * fic_significados){
  bool aux = true;
  ifstream arbol (fich_jerarquia);
  arbol>>ab;
  aux = lee_significados(fic_significados);
  return aux;
}

void Ontologias::clear(){
  ab.clear();
  significados.clear();
}


map<string,set<string> > Ontologias::GetSinonimos(const string & palabra)const{
  const_iterator ite;
  map<string,set<string> > aux;
  set<string>::iterator it;
  bool encontrado=false;
  //int indice;
  for(ite=begin();ite!=end() and !encontrado;++ite){
    for(it=(*ite).first.begin();it!=(*ite).first.end();++it){

      if((*it) == palabra){
        encontrado = true;

      }
    }
  }
  //indice = (*ite).second;
  //string significado = significados.find(1);
  //aux[significado] = (*ite).first;
  return aux;
}

/*____________________________________________________________ */
