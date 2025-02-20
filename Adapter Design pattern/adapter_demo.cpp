#include<iostream>
using namespace std;

class XMLData{
    string xmlData;
    public:
    XMLData(string pXmlData){
        xmlData = pXmlData;
    }
    string getXMLData(){
        return xmlData;
    }
};

class DataAnalyticsTool{
    string jsonData;
    public:
    DataAnalyticsTool(){}
    DataAnalyticsTool(string pJsonData){
        jsonData = pJsonData;
    }
    virtual void analyseData(){
        cout<<" Analysing Data "<<jsonData<<endl;
    }
};


class Adapter : public DataAnalyticsTool{
    XMLData* XMLData;
    public:
    Adapter(XMLData* pXMLData){
        xmlData = pXMLData;
    }

    void analyseData() override{
        cout<<" Converting XML DAta "<<XMLData->getXMLData()<<" to JSON Data "<<endl;
        cout<<" Analysing the converted JSON Data "<<endl;
    }
}


class Clinet{
    public:
    void ProcessData(DataAnalyticsTool* tool){
        tool -> analyseData();
    }
};


int mian(){
    XMLData* xmlData = new XMLData("Sample XML data");
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client* client = new Client;
    client -> ProcessData(tool);
    return 0;
}