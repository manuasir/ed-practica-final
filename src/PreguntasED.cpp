void PreguntasED::MuestraTematicas(){
  Ontologias::iterator_level itl;
  int cnt=tl;
  for (itl=Ot.beginl(tl);itl!=Ot.endl(); ++itl){
    pair<set<string>,int> aux= *itl;
    set<string>::iterator sit=aux.first.begin();
    cout<<"Temática "<<cnt;
    cnt++;
    while (sit!=aux.first.end()){
      cout<<*sit<<", ";
      temas.push_back(itl);
      ++sit;
    }
    cout<<endl;
  }
}

void PreguntasED::SetTematica(int i){
  tematica_escogida = i;
}

string PreguntasED::GetTitleTematica(){
  set<string> miSet = (*temas[tematica_escogida]).first;
  set<string>::iterator ite;
  string aux;
  for(ite=miSet.begin();ite!=miSet.end();++ite){
    aux+=" ";
    aux+=(*ite);
  }
  return aux;
}

void PreguntasED::IniciaConceptosTemaEscogido(){
  Ontologias::iterator_level ite = temas[tematica_escogida];
  Ontologias::iterator it(ite);
  set<string>::iterator itSet;
  for(it=Ot.begin();it!=Ot.end();++it){
    preguntas_tema.push_back(it);
  }
}

pair<set<string>,string> PreguntasED::SacaPregunta(){
  Ontologias::iterator ite = preguntas_tema.back();
  string cadena = Ot.GetDefinicion((*ite).second);
  pair<set<string>,string> aux((*ite).first, cadena);
  preguntas_tema.pop_back();
  return aux;
}

pair<set<string>,string> PreguntasED::GetPregunta(int i){
  Ontologias::iterator ite = preguntas_tema[i];
  string cadena = Ot.GetDefinicion((*ite).second);
  pair<set<string>,string> aux((*ite).first, cadena);
  preguntas_tema.pop_back();
  return aux;
}
