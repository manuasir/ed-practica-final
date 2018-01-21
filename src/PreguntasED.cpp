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
