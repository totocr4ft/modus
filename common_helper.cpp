#include <common_helper.h>

//----------------------  EXPLODE LIKE PHP ------------------//
QVector<QString> explode(QString separator,QString t){
QVector<QString>  m;
int i,y;
y = t.count();
QString temp="";
for(i=0; i < y; i++){
   if(t[i] != separator[0]){
    temp.append(t[i]);
   }else{
    m.append(temp);
    temp.clear();
   }
   if(i==y-1){
    m.append(temp);
    temp.clear();
   }
}
return m;
}

//------- DELPHI TSTRINGLIST COMMATEXT TO QMAP ---------------//
QMap<QString, QString> TSlistToQmap(QString t){
QMap<QString, QString> m;
QVector<QString> a;
QVector<QString> v = explode(",",t);
for(int i=0;i < v.length(); i++ ){
 a = explode("=",v[i]);
 m.insert(a[0],a[1]);
}
return m;
};
