//Programa db_size.cpp estima el tamaño de una base de datos.
//Imprime tamaño de una fila, una página y todas las páginas.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int vc=0, max_vc=0, t_vc=0, in=0, fl=0, lo=0, da=0, ts=0;
	int tables=0, bytes_per_row=0, rows_per_table=0, total_rows=0, bytes_per_table=0, bytes_per_page=8096, rows_per_page=0, pages=0, total_bytes=0;
	
	//Encabezado
	cout<<endl;
	cout<<"Estimaci\242n tama\244o base de datos."<<endl<<endl;
	
	//Consulta de datos de la bd
	cout<<"A continuaci\242n introduzca los datos requeridos para la estimaci\242n."<<endl;
	cout<<"# de tablas en la bd:";
	cin>>tables;
	//Bytes por tabla
	for(int i=0; i<tables; i++)
	{
		cout<<"# de columnas VARCHAR en la tabla "<<i+1<<": ";
		cin>>vc;
		vector<int> col_vc;
		for(int j=0; j<vc; j++)
		{
			cout<<"Caracteres m\240ximos columna VARCHAR "<<j+1<<": ";
			cin>>max_vc;
			t_vc=t_vc+(max_vc+1); //Total bytes de VARCHAR
		}
		bytes_per_row=bytes_per_row+t_vc;
		
		cout<<"# de columnas INTEGER en la tabla "<<i+1<<": ";
		cin>>in;
		in=in*4; //Total bytes de INTEGER
		bytes_per_row=bytes_per_row+in;
		
		cout<<"# de columnas FLOAT en la tabla "<<i+1<<": ";
		cin>>fl;
		fl=fl*4; //Total bytes de FLOAT
		bytes_per_row=bytes_per_row+fl;
		
		cout<<"# de columnas LONG en la tabla "<<i+1<<": ";
		cin>>lo;
		lo=lo*8; //Total bytes de LONG
		bytes_per_row=bytes_per_row+lo;
		
		cout<<"# de columnas DATE en la tabla "<<i+1<<": ";
		cin>>da;
		da=da*3; //Total bytes de DATE
		bytes_per_row=bytes_per_row+da;
		
		cout<<"# de columnas TIMESTAMP en la tabla "<<i+1<<": ";
		cin>>ts;
		ts=ts*4; //Total bytes de TIMESTAMP
		bytes_per_row=bytes_per_row+ts; //Total de bytes por registro
		
		cout<<"# de registros aproximados que almacenar\240 la tabla "<<i+1<<": ";
		cin>>rows_per_table; //Registros por tabla
		total_rows=total_rows+rows_per_table;
		bytes_per_table=rows_per_table*bytes_per_row; //Total de bytes por tabla
		//total_bytes=total_bytes+bytes_per_table; //Total de bytes de la bd
	}
	//Bytes por página
	//bytes_per_page=bytes_per_row*rows_per_page;
	rows_per_page=bytes_per_page/(bytes_per_row+2); //filas por página
	int free_rows=rows_per_page*(1/bytes_per_row);
	pages=total_rows/(rows_per_table-free_rows);
	
	
	//Impresión resultados
	if(tables==0)
	{
		cout<<endl;
		cout<<"El tama\244o de una base de datos sin tablas es 0"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"El tama\244o de una base de datos con estas catacter\241sticas es: "<<endl;
		cout<<"Bytes por cada registro: "<<bytes_per_row<<endl;
		cout<<"Bytes por cada p\240gina: "<<bytes_per_page<<endl;
		//cout<<"Bytes por todas las p\240ginas: "<<total_bytes<<endl;
		cout<<"Bytes por todas las p\240ginas: "<<bytes_per_page*pages<<endl;
	}
}

//Para agregar un caracter del código ASCII, sumar 80 al código.
//á = \240
//é = \210
//í = \241
//ó = \242
//ú = \243
//ñ = \244