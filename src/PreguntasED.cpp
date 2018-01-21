void PreguntasED::MuestraTematicas(){
  cout<< "Las temáticas posibles a nivel"<<tl<<" son:"<<endl;
  Ontologias::iterator_level itl;
  int cnt=tl;
  for (itl=Ot.beginl(tl);itl!=Ot.endl(); ++itl){
    pair<set<string>,int> aux= *itl;
    set<string>::iterator sit=aux.first.begin();
    cout<<"Temática "<<cnt;
    cnt++;
    while (sit!=aux.first.end()){
      cout<<*sit<<", ";++sit;
    }
    cout<<endl;
  }
}
