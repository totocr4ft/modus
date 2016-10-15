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
}

QString getVersionString(QString fName)
{
// first of all, GetFileVersionInfoSize
DWORD dwHandle;
DWORD dwLen = GetFileVersionInfoSize(fName.toStdWString().c_str(), &dwHandle);
// GetFileVersionInfo
LPVOID lpData = new BYTE[dwLen];
if(!GetFileVersionInfo(fName.toStdWString().c_str(), dwHandle, dwLen, lpData))
{
//qDebug() << “error in GetFileVersionInfo”;
delete[] lpData;
return "";
}

// VerQueryValue
VS_FIXEDFILEINFO *lpBuffer = NULL;
UINT uLen;

if(!VerQueryValue(lpData,
QString("\\").toStdWString().c_str(),
(LPVOID*)&lpBuffer,
&uLen))
{
qDebug() << "error in VerQueryValue"; delete[] lpData; return ""; } return QString::number( (lpBuffer->dwFileVersionMS >> 16 ) & 0xffff ) +
QString::number( ( lpBuffer->dwFileVersionMS) & 0xffff ) +
QString::number( ( lpBuffer->dwFileVersionLS >> 16 ) & 0xffff ) +
QString::number( ( lpBuffer->dwFileVersionLS) & 0xffff );
}
