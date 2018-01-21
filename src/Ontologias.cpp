
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

bool Ontologias::lee_significados(const char * fich_sig){
  ifstream significados (fich_sig);
  string line;
  while (getline(significados, line)) {
    string index = line;
    const char * cstr = line.c_str();
    //cout << "una linea:" << index << '\n';
    int i;
    for(i=0 ; i<int(line.size()) and cstr[i] != ' ';i++);
    cout << line.substr(0,i) << '\n';
  }
  return true;
}


bool Ontologias::Lee(const char * fich_jerarquia,const char * fic_significados){
  bool aux = true;
  ifstream arbol (fich_jerarquia);
  arbol>>ab;
  aux = lee_significados(fic_significados);
  return aux;
}

/*____________________________________________________________ */
