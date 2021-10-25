#pragma once
#include <msclr\marshal_cppstd.h>
#include "CsvReader.h"
#include "CsvWriter.h"
#include "Cancion.h"
#include "List.h"
#include "Pila.h"
#include "Cola.h"

namespace Proyecto1JULIORUIZ1284719 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Musica : public System::Windows::Forms::Form
	{
		//inicializando la pila y la cola
		Pila* playlist;
		Cola* reproduccion;
	private: System::Windows::Forms::TextBox^ txtNombre;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtArtista;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ btnSincronizar;
	private: System::Windows::Forms::Button^ btnSiguiente;
	private: System::Windows::Forms::Button^ btnAnterior;
	private: System::Windows::Forms::Button^ btnRandom;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnAbrir;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		   Cancion* actual;
	public:
		Musica()
		{
			InitializeComponent();
			LeerArchivo("songs.csv");
		}

		void LeerArchivo(string ruta)
		{
			try
			{
				CsvReader* csv = new CsvReader(ruta);
				playlist = new Pila();
				reproduccion = new Cola();
				actual = nullptr;

				string data;
				while (csv->Read(data)) //   "Playa - Nicky Jam"
				{
					String^ line = gcnew String(data.c_str());// c_str() extrae del string la ruta pero con formato const char
					//String recive ese tipo de dato que es más neutro para crear el objeto de Visual C++

					// ["Playa Nicky Jam"] -> 1
					// ["Playa ", "Nicky Jam"] -> 2

					String^ Nombre = line->Split('-')[0]->Trim();//se obtiene el nombre

					String^ Artista = "";
					if (line->Split('-')->Length > 1)//si el tamaño de ese arreglo es mayor a 1
						Artista = line->Split('-')[1]->Trim();//se obstiene el artista y con trim es una operación de cadena en la que se eliminan espacios en blanco adicionales del inicio y el final de una cadena

					//De (String^) a (string)
					//stackoverflowhttps://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring
					string nombre = msclr::interop::marshal_as<std::string>(Nombre);
					string artista = msclr::interop::marshal_as<std::string>(Artista);

					nombre = (nombre == "") ? "Cancion sin nombre" : nombre;
					artista = (artista == "") ? "desconocido" : artista;
					//operador ternario es, si artista tiene un espacio en blanco devuelva desconocido si no 
					//que devuelva el artista

					Cancion* cancion = new Cancion(nombre, artista);
					playlist->push(cancion);
				}

				LlenarDatos();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("LECTURA DE ARCHIVO" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	protected:
		~Musica()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbxPlayList;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblCancion;

	private: System::Windows::Forms::Button^ btnOrdenar;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ rbParametroCancion;
	private: System::Windows::Forms::RadioButton^ rbParametroArtista;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ rbOrdenDesc;
	private: System::Windows::Forms::RadioButton^ rbOrdenAsc;
	private: System::Windows::Forms::ListBox^ lbxReproduccion;

	private: System::Windows::Forms::Button^ btnReproducir;
	private: System::ComponentModel::Container^ components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Musica::typeid));
			   this->lbxPlayList = (gcnew System::Windows::Forms::ListBox());
			   this->btnOrdenar = (gcnew System::Windows::Forms::Button());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->rbParametroArtista = (gcnew System::Windows::Forms::RadioButton());
			   this->rbParametroCancion = (gcnew System::Windows::Forms::RadioButton());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->rbOrdenDesc = (gcnew System::Windows::Forms::RadioButton());
			   this->rbOrdenAsc = (gcnew System::Windows::Forms::RadioButton());
			   this->lbxReproduccion = (gcnew System::Windows::Forms::ListBox());
			   this->btnReproducir = (gcnew System::Windows::Forms::Button());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->lblCancion = (gcnew System::Windows::Forms::Label());
			   this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->txtArtista = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->btnAgregar = (gcnew System::Windows::Forms::Button());
			   this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			   this->btnSincronizar = (gcnew System::Windows::Forms::Button());
			   this->btnSiguiente = (gcnew System::Windows::Forms::Button());
			   this->btnAnterior = (gcnew System::Windows::Forms::Button());
			   this->btnRandom = (gcnew System::Windows::Forms::Button());
			   this->btnEliminar = (gcnew System::Windows::Forms::Button());
			   this->btnGuardar = (gcnew System::Windows::Forms::Button());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			   this->btnAbrir = (gcnew System::Windows::Forms::Button());
			   this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   this->groupBox3->SuspendLayout();
			   this->groupBox4->SuspendLayout();
			   this->groupBox5->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // lbxPlayList
			   // 
			   this->lbxPlayList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->lbxPlayList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->lbxPlayList->ForeColor = System::Drawing::Color::White;
			   this->lbxPlayList->FormattingEnabled = true;
			   this->lbxPlayList->ItemHeight = 19;
			   this->lbxPlayList->Location = System::Drawing::Point(35, 40);
			   this->lbxPlayList->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->lbxPlayList->Name = L"lbxPlayList";
			   this->lbxPlayList->Size = System::Drawing::Size(291, 190);
			   this->lbxPlayList->TabIndex = 0;
			   // 
			   // btnOrdenar
			   // 
			   this->btnOrdenar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnOrdenar->FlatAppearance->BorderSize = 0;
			   this->btnOrdenar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnOrdenar->Location = System::Drawing::Point(331, 236);
			   this->btnOrdenar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnOrdenar->Name = L"btnOrdenar";
			   this->btnOrdenar->Size = System::Drawing::Size(164, 34);
			   this->btnOrdenar->TabIndex = 2;
			   this->btnOrdenar->Text = L"Ordenar";
			   this->btnOrdenar->UseVisualStyleBackColor = false;
			   this->btnOrdenar->Click += gcnew System::EventHandler(this, &Musica::btnOrdenar_Click);
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->groupBox1->Controls->Add(this->rbParametroArtista);
			   this->groupBox1->Controls->Add(this->rbParametroCancion);
			   this->groupBox1->Location = System::Drawing::Point(331, 40);
			   this->groupBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox1->Size = System::Drawing::Size(164, 84);
			   this->groupBox1->TabIndex = 3;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Parámetro";
			   // 
			   // rbParametroArtista
			   // 
			   this->rbParametroArtista->AutoSize = true;
			   this->rbParametroArtista->Location = System::Drawing::Point(28, 53);
			   this->rbParametroArtista->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->rbParametroArtista->Name = L"rbParametroArtista";
			   this->rbParametroArtista->Size = System::Drawing::Size(68, 23);
			   this->rbParametroArtista->TabIndex = 5;
			   this->rbParametroArtista->TabStop = true;
			   this->rbParametroArtista->Text = L"Artista";
			   this->rbParametroArtista->UseVisualStyleBackColor = true;
			   // 
			   // rbParametroCancion
			   // 
			   this->rbParametroCancion->AutoSize = true;
			   this->rbParametroCancion->Location = System::Drawing::Point(28, 23);
			   this->rbParametroCancion->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->rbParametroCancion->Name = L"rbParametroCancion";
			   this->rbParametroCancion->Size = System::Drawing::Size(87, 23);
			   this->rbParametroCancion->TabIndex = 4;
			   this->rbParametroCancion->TabStop = true;
			   this->rbParametroCancion->Text = L"Canción";
			   this->rbParametroCancion->UseVisualStyleBackColor = true;
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->groupBox2->Controls->Add(this->rbOrdenDesc);
			   this->groupBox2->Controls->Add(this->rbOrdenAsc);
			   this->groupBox2->Location = System::Drawing::Point(331, 146);
			   this->groupBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox2->Size = System::Drawing::Size(164, 84);
			   this->groupBox2->TabIndex = 6;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Órden";
			   // 
			   // rbOrdenDesc
			   // 
			   this->rbOrdenDesc->AutoSize = true;
			   this->rbOrdenDesc->Location = System::Drawing::Point(28, 53);
			   this->rbOrdenDesc->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->rbOrdenDesc->Name = L"rbOrdenDesc";
			   this->rbOrdenDesc->Size = System::Drawing::Size(120, 23);
			   this->rbOrdenDesc->TabIndex = 5;
			   this->rbOrdenDesc->TabStop = true;
			   this->rbOrdenDesc->Text = L"Descendente";
			   this->rbOrdenDesc->UseVisualStyleBackColor = true;
			   // 
			   // rbOrdenAsc
			   // 
			   this->rbOrdenAsc->AutoSize = true;
			   this->rbOrdenAsc->Location = System::Drawing::Point(28, 23);
			   this->rbOrdenAsc->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->rbOrdenAsc->Name = L"rbOrdenAsc";
			   this->rbOrdenAsc->Size = System::Drawing::Size(110, 23);
			   this->rbOrdenAsc->TabIndex = 4;
			   this->rbOrdenAsc->TabStop = true;
			   this->rbOrdenAsc->Text = L"Ascendente";
			   this->rbOrdenAsc->UseVisualStyleBackColor = true;
			   // 
			   // lbxReproduccion
			   // 
			   this->lbxReproduccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->lbxReproduccion->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->lbxReproduccion->ForeColor = System::Drawing::Color::White;
			   this->lbxReproduccion->FormattingEnabled = true;
			   this->lbxReproduccion->ItemHeight = 19;
			   this->lbxReproduccion->Location = System::Drawing::Point(39, 42);
			   this->lbxReproduccion->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->lbxReproduccion->Name = L"lbxReproduccion";
			   this->lbxReproduccion->Size = System::Drawing::Size(225, 190);
			   this->lbxReproduccion->TabIndex = 7;
			   // 
			   // btnReproducir
			   // 
			   this->btnReproducir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnReproducir->FlatAppearance->BorderSize = 0;
			   this->btnReproducir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnReproducir->Location = System::Drawing::Point(35, 236);
			   this->btnReproducir->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnReproducir->Name = L"btnReproducir";
			   this->btnReproducir->Size = System::Drawing::Size(291, 34);
			   this->btnReproducir->TabIndex = 9;
			   this->btnReproducir->Text = L"Reproducir";
			   this->btnReproducir->UseVisualStyleBackColor = false;
			   this->btnReproducir->Click += gcnew System::EventHandler(this, &Musica::btnReproducir_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::Transparent;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(400, 677);
			   this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(150, 25);
			   this->label3->TabIndex = 10;
			   this->label3->Text = L"Escuchando:";
			   // 
			   // lblCancion
			   // 
			   this->lblCancion->AutoSize = true;
			   this->lblCancion->BackColor = System::Drawing::Color::Transparent;
			   this->lblCancion->Font = (gcnew System::Drawing::Font(L"Century Gothic", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblCancion->Location = System::Drawing::Point(690, 677);
			   this->lblCancion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblCancion->Name = L"lblCancion";
			   this->lblCancion->Size = System::Drawing::Size(97, 25);
			   this->lblCancion->TabIndex = 11;
			   this->lblCancion->Text = L"ninguno";
			   // 
			   // txtNombre
			   // 
			   this->txtNombre->BackColor = System::Drawing::Color::LightSkyBlue;
			   this->txtNombre->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->txtNombre->ForeColor = System::Drawing::Color::Black;
			   this->txtNombre->Location = System::Drawing::Point(15, 43);
			   this->txtNombre->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->txtNombre->Name = L"txtNombre";
			   this->txtNombre->ShortcutsEnabled = false;
			   this->txtNombre->Size = System::Drawing::Size(124, 17);
			   this->txtNombre->TabIndex = 12;
			   this->txtNombre->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Musica::txtNombre_KeyPress);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(15, 20);
			   this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(68, 19);
			   this->label4->TabIndex = 13;
			   this->label4->Text = L"Nombre:";
			   // 
			   // txtArtista
			   // 
			   this->txtArtista->BackColor = System::Drawing::Color::LightSkyBlue;
			   this->txtArtista->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->txtArtista->ForeColor = System::Drawing::Color::Black;
			   this->txtArtista->Location = System::Drawing::Point(15, 93);
			   this->txtArtista->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->txtArtista->Name = L"txtArtista";
			   this->txtArtista->ShortcutsEnabled = false;
			   this->txtArtista->Size = System::Drawing::Size(124, 17);
			   this->txtArtista->TabIndex = 14;
			   this->txtArtista->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Musica::txtArtista_KeyPress);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(15, 69);
			   this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(54, 19);
			   this->label5->TabIndex = 15;
			   this->label5->Text = L"Artista:";
			   // 
			   // btnAgregar
			   // 
			   this->btnAgregar->BackColor = System::Drawing::Color::LightSkyBlue;
			   this->btnAgregar->FlatAppearance->BorderSize = 0;
			   this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAgregar->Location = System::Drawing::Point(18, 134);
			   this->btnAgregar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnAgregar->Name = L"btnAgregar";
			   this->btnAgregar->Size = System::Drawing::Size(124, 44);
			   this->btnAgregar->TabIndex = 16;
			   this->btnAgregar->Text = L"Agregar";
			   this->btnAgregar->UseVisualStyleBackColor = false;
			   this->btnAgregar->Click += gcnew System::EventHandler(this, &Musica::btnAgregar_Click);
			   // 
			   // groupBox3
			   // 
			   this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->groupBox3->Controls->Add(this->label4);
			   this->groupBox3->Controls->Add(this->btnAgregar);
			   this->groupBox3->Controls->Add(this->txtNombre);
			   this->groupBox3->Controls->Add(this->label5);
			   this->groupBox3->Controls->Add(this->txtArtista);
			   this->groupBox3->Location = System::Drawing::Point(269, 42);
			   this->groupBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox3->Name = L"groupBox3";
			   this->groupBox3->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox3->Size = System::Drawing::Size(158, 189);
			   this->groupBox3->TabIndex = 17;
			   this->groupBox3->TabStop = false;
			   this->groupBox3->Text = L"Agregar Cancion";
			   // 
			   // btnSincronizar
			   // 
			   this->btnSincronizar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnSincronizar->FlatAppearance->BorderSize = 0;
			   this->btnSincronizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSincronizar->Location = System::Drawing::Point(39, 241);
			   this->btnSincronizar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnSincronizar->Name = L"btnSincronizar";
			   this->btnSincronizar->Size = System::Drawing::Size(388, 33);
			   this->btnSincronizar->TabIndex = 18;
			   this->btnSincronizar->Text = L"Sincronizar";
			   this->btnSincronizar->UseVisualStyleBackColor = false;
			   this->btnSincronizar->Click += gcnew System::EventHandler(this, &Musica::btnSincronizar_Click);
			   // 
			   // btnSiguiente
			   // 
			   this->btnSiguiente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnSiguiente->FlatAppearance->BorderSize = 0;
			   this->btnSiguiente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnSiguiente->Location = System::Drawing::Point(170, 280);
			   this->btnSiguiente->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnSiguiente->Name = L"btnSiguiente";
			   this->btnSiguiente->Size = System::Drawing::Size(141, 33);
			   this->btnSiguiente->TabIndex = 19;
			   this->btnSiguiente->Text = L"Siguiente";
			   this->btnSiguiente->UseVisualStyleBackColor = false;
			   this->btnSiguiente->Click += gcnew System::EventHandler(this, &Musica::btnSiguiente_Click);
			   // 
			   // btnAnterior
			   // 
			   this->btnAnterior->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnAnterior->FlatAppearance->BorderSize = 0;
			   this->btnAnterior->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAnterior->Location = System::Drawing::Point(39, 280);
			   this->btnAnterior->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnAnterior->Name = L"btnAnterior";
			   this->btnAnterior->Size = System::Drawing::Size(127, 33);
			   this->btnAnterior->TabIndex = 20;
			   this->btnAnterior->Text = L"Anterior";
			   this->btnAnterior->UseVisualStyleBackColor = false;
			   this->btnAnterior->Click += gcnew System::EventHandler(this, &Musica::btnAnterior_Click);
			   // 
			   // btnRandom
			   // 
			   this->btnRandom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnRandom->FlatAppearance->BorderSize = 0;
			   this->btnRandom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnRandom->Location = System::Drawing::Point(315, 280);
			   this->btnRandom->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnRandom->Name = L"btnRandom";
			   this->btnRandom->Size = System::Drawing::Size(112, 33);
			   this->btnRandom->TabIndex = 21;
			   this->btnRandom->Text = L"Random";
			   this->btnRandom->UseVisualStyleBackColor = false;
			   this->btnRandom->Click += gcnew System::EventHandler(this, &Musica::btnRandom_Click);
			   // 
			   // btnEliminar
			   // 
			   this->btnEliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnEliminar->FlatAppearance->BorderSize = 0;
			   this->btnEliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnEliminar->Location = System::Drawing::Point(39, 319);
			   this->btnEliminar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnEliminar->Name = L"btnEliminar";
			   this->btnEliminar->Size = System::Drawing::Size(388, 27);
			   this->btnEliminar->TabIndex = 22;
			   this->btnEliminar->Text = L"Eliminar";
			   this->btnEliminar->UseVisualStyleBackColor = false;
			   this->btnEliminar->Click += gcnew System::EventHandler(this, &Musica::btnEliminar_Click);
			   // 
			   // btnGuardar
			   // 
			   this->btnGuardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnGuardar->FlatAppearance->BorderSize = 0;
			   this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnGuardar->Location = System::Drawing::Point(272, 276);
			   this->btnGuardar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnGuardar->Name = L"btnGuardar";
			   this->btnGuardar->Size = System::Drawing::Size(223, 42);
			   this->btnGuardar->TabIndex = 23;
			   this->btnGuardar->Text = L"Guardar";
			   this->btnGuardar->UseVisualStyleBackColor = false;
			   this->btnGuardar->Click += gcnew System::EventHandler(this, &Musica::btnGuardar_Click);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(64, 15);
			   this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(75, 19);
			   this->label6->TabIndex = 24;
			   this->label6->Text = L"CANCIÓN";
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(222, 15);
			   this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(56, 19);
			   this->label7->TabIndex = 25;
			   this->label7->Text = L"ARTISTA";
			   // 
			   // groupBox4
			   // 
			   this->groupBox4->BackColor = System::Drawing::Color::Black;
			   this->groupBox4->Controls->Add(this->btnAbrir);
			   this->groupBox4->Controls->Add(this->lbxPlayList);
			   this->groupBox4->Controls->Add(this->btnOrdenar);
			   this->groupBox4->Controls->Add(this->label7);
			   this->groupBox4->Controls->Add(this->groupBox1);
			   this->groupBox4->Controls->Add(this->label6);
			   this->groupBox4->Controls->Add(this->groupBox2);
			   this->groupBox4->Controls->Add(this->btnGuardar);
			   this->groupBox4->Controls->Add(this->btnReproducir);
			   this->groupBox4->Location = System::Drawing::Point(161, 280);
			   this->groupBox4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox4->Name = L"groupBox4";
			   this->groupBox4->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox4->Size = System::Drawing::Size(529, 354);
			   this->groupBox4->TabIndex = 27;
			   this->groupBox4->TabStop = false;
			   this->groupBox4->Text = L"Play List:";
			   // 
			   // btnAbrir
			   // 
			   this->btnAbrir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				   static_cast<System::Int32>(static_cast<System::Byte>(148)));
			   this->btnAbrir->FlatAppearance->BorderSize = 0;
			   this->btnAbrir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAbrir->Location = System::Drawing::Point(35, 276);
			   this->btnAbrir->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnAbrir->Name = L"btnAbrir";
			   this->btnAbrir->Size = System::Drawing::Size(233, 42);
			   this->btnAbrir->TabIndex = 26;
			   this->btnAbrir->Text = L"Abrir";
			   this->btnAbrir->UseVisualStyleBackColor = false;
			   this->btnAbrir->Click += gcnew System::EventHandler(this, &Musica::btnAbrir_Click);
			   // 
			   // groupBox5
			   // 
			   this->groupBox5->BackColor = System::Drawing::Color::Black;
			   this->groupBox5->Controls->Add(this->label1);
			   this->groupBox5->Controls->Add(this->lbxReproduccion);
			   this->groupBox5->Controls->Add(this->label2);
			   this->groupBox5->Controls->Add(this->groupBox3);
			   this->groupBox5->Controls->Add(this->btnSincronizar);
			   this->groupBox5->Controls->Add(this->btnSiguiente);
			   this->groupBox5->Controls->Add(this->btnAnterior);
			   this->groupBox5->Controls->Add(this->btnEliminar);
			   this->groupBox5->Controls->Add(this->btnRandom);
			   this->groupBox5->Location = System::Drawing::Point(707, 278);
			   this->groupBox5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox5->Name = L"groupBox5";
			   this->groupBox5->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->groupBox5->Size = System::Drawing::Size(462, 356);
			   this->groupBox5->TabIndex = 28;
			   this->groupBox5->TabStop = false;
			   this->groupBox5->Text = L"Reproducción";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(189, 17);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(56, 19);
			   this->label1->TabIndex = 27;
			   this->label1->Text = L"ARTISTA";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(65, 17);
			   this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(75, 19);
			   this->label2->TabIndex = 26;
			   this->label2->Text = L"CANCIÓN";
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // Musica
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 19);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->AutoSize = true;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				   static_cast<System::Int32>(static_cast<System::Byte>(82)));
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1235, 734);
			   this->Controls->Add(this->groupBox5);
			   this->Controls->Add(this->groupBox4);
			   this->Controls->Add(this->lblCancion);
			   this->Controls->Add(this->label3);
			   this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ForeColor = System::Drawing::Color::White;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"Musica";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Musica";
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   this->groupBox3->ResumeLayout(false);
			   this->groupBox3->PerformLayout();
			   this->groupBox4->ResumeLayout(false);
			   this->groupBox4->PerformLayout();
			   this->groupBox5->ResumeLayout(false);
			   this->groupBox5->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
	#pragma endregion

	void LlenarDatos()
	{
		lbxPlayList->Items->Clear();
		for (int i = 0; i < playlist->size(); i++)
			lbxPlayList->Items->Add(gcnew String(playlist->GetValue(i)->ToString().c_str()));//para acceder a la cancion se utiliza el ->getvalue(i)
			
		lbxReproduccion->Items->Clear();
		for (int i = 0; i < reproduccion->size(); i++)//para que recorra toda la reproduccion
			lbxReproduccion->Items->Add(gcnew String(reproduccion->GetValue(i)->ToString().c_str()));//para acceder a la cancion se utiliza el ->getvalue(i)

		if (actual == nullptr)
			lblCancion->Text = "ninguno";//a un inicio no hay cancion que se este escuchando
		else
			lblCancion->Text = gcnew String(actual->ToString().c_str());//para que la cancion que se este escuchando se imprima en el lblcancion
	}
	Void btnOrdenar_Click(Object^ sender, EventArgs^ e)
	{
		//la playlist en su interior esta compuesta de la lista 
		//para ordenar los datos se uso una lista haciendo metodos para cada tipo de ordenamiento , en la pila se crearon funciones de ordenamiento que lo unico que hacen es llamar a la misma funcion pero de la lista, una funcion puente que conecta el forms con la lista interna de la pila ;) 

		try
		{
			//para que el usuario ingrese que tipo de ordenamiento quiere escojer
			if (rbParametroArtista->Checked)
			{
				if (rbOrdenAsc->Checked)
				{
					playlist->OrdenarArtistaAsendente();
				}
				if (rbOrdenDesc->Checked)
				{
					playlist->OrdenarArtistaDescendente();
				}
			}
			if (rbParametroCancion->Checked)
			{
				if (rbOrdenAsc->Checked)
				{
					playlist->OrdenarCancionAsendente();
				}
				if (rbOrdenDesc->Checked)
				{
					playlist->OrdenarCancionDescendente();
				}
			}
			LlenarDatos();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("ORDENAMIENTO" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnReproducir_Click(Object^ sender, EventArgs^ e)
	{
		try
		{
			//se va quitando la cancion que el usuario le da a reproducir
			actual = playlist->pop();

			//para que la cola de reproduccion se coloque en la pila playlist cuando el usuario saque todas de la playlist 
			if (playlist->size() == 0)
			{
				btnSincronizar_Click(sender, e);//mande a llamar a al funcion de sincronizar para no volverla a escribir ;3
			}

			LlenarDatos();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("REPRODUCCION" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnAgregar_Click(Object^ sender, EventArgs^ e) 
	{
		try
		{
			string nombre = msclr::interop::marshal_as<std::string>(txtNombre->Text);//para que el usuario agregue el nombre de la cancion
			string artista = msclr::interop::marshal_as<std::string>(txtArtista->Text);//para que el usuario agregue el artista de la cancion

			nombre = (nombre == "") ? "Cancion sin nombre" : nombre;//por si no tiene nombre se coloca como cancion sin nombre
			artista = (artista == "") ? "desconocido" : artista;//si el artista es desconocido 

			nombre[0] = toupper(nombre[0]);//para validar que el usuario ingrese la primera letra en mayuscula ya que el ordenamiento se genera con mayusculas
			artista[0] = (artista != "desconocido") ? toupper(artista[0]) : artista[0];

			Cancion* cancion = new Cancion(nombre, artista);
			reproduccion->enqueue(cancion);//para poner en la cola de reproduccion

			txtNombre->Clear();
			txtArtista->Clear();

			LlenarDatos();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("AGREGAR" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnSincronizar_Click(Object^ sender, EventArgs^ e)
	{
		try
		{
			//para poner de la cola a pila 
			while (reproduccion->queueempty() == false)
			{
				playlist->push(reproduccion->dequeue());
			}
			LlenarDatos();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("SINCRONIZAR" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnSiguiente_Click(Object^ sender, EventArgs^ e) 
	{
		try
		{
			//como lo entendi para el siguiente es que a la cola de reproduccion lo desencola y le da un push en la pila playlist 
			if (reproduccion->size() > 0)
			{
				playlist->push(reproduccion->dequeue());
				LlenarDatos();
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show("SIGUIENTE" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnAnterior_Click(Object^ sender, EventArgs^ e) 
	{
		try
		{
			//a la playlist le hace un pop y lo encola en reproduccion
			if (playlist->size() > 0)
			{
				reproduccion->enqueue(playlist->pop());
				LlenarDatos();
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show("ANTERIOR" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnRandom_Click(Object^ sender, EventArgs^ e) 
	{
		try
		{
			if (reproduccion->size() > 0)//si es que hay canciones en reproduccion 
			{
				int size = reproduccion->size();//una variable int size que guarde el tamaño actual de la lista de reproduccion y que nunca varie ;s
				int pos = rand() % size;//una variable int pos para almacenarle un numero randoms desde 0 hasta el tamaño de la lista de reproduccion
				Cola* temp = new Cola();

				for (int i = 0; i < size; i++)
				{
					if (i != pos)//para todo donde i es diferente de posicion los agrego al temporal .  son los que quedan afuera por asi decirlo del que se genero random ;d
						temp->enqueue(reproduccion->dequeue());//se desencola el elemento y se colocaran en una cola temporal 
					else//si es que es igual a la posicion que se genero random 
						playlist->push(reproduccion->dequeue());//el que genero el random sale o se desencola y le da un push a la pila playlist
				}

				while (temp->queueempty() == false)//mientras que la cola temporal no este vacio 
				{
					reproduccion->enqueue(temp->dequeue());//se pasara del temporal a la lista de reproduccion
					//terminara hasta que el temp quede vacio
				}
				LlenarDatos();
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show("RANDOM" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	Void btnEliminar_Click(Object^ sender, EventArgs^ e) 
	{
		//el usuario debe ser capaz de eliminar una cancion de la cola de reproduccion
		delete reproduccion->dequeue();
		LlenarDatos();
	}
	Void btnGuardar_Click(Object^ sender, EventArgs^ e)
	{
		try
		{
			//para poder exportar el archivo con la playlist actual
			saveFileDialog1->Filter = "CSV Files|*.csv|TXT Files|*.txt|All Files|*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				CsvWriter* csv = new CsvWriter();
				Pila* temp = new Pila();
				while (playlist->stackempty() == false)
				{
					Cancion* cancion = playlist->pop();
					string info = cancion->ToString();
					csv->Write(info);
					temp->push(cancion);
				}

				string file = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
				csv->Save(file);

				while (temp->stackempty() == false)
				{
					playlist->push(temp->pop());
				}
			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show("EXPORTACION DEFECTUOSA" + e->Message, "ERROR DETECTADO", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
private: Void txtNombre_KeyPress(Object^ sender,KeyPressEventArgs^ e) {
	//validacion de solo letras segun la tabla ascii del 65 al 122 se tomo como letra sea mayuscula o minuscula
	if ((e->KeyChar >= 33 && e->KeyChar <= 64) || (e->KeyChar >= 91 && e->KeyChar <= 96) || (e->KeyChar >= 123 && e->KeyChar <= 255))
	{
		MessageBox::Show("SOLO LETRAS","ALERTA", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		e->Handled = true;
		return;
	}
}
private: Void txtArtista_KeyPress(Object^ sender,KeyPressEventArgs^ e) {
	if ((e->KeyChar >= 33 && e->KeyChar <= 64) || (e->KeyChar >= 91 && e->KeyChar <= 96) || (e->KeyChar >= 123 && e->KeyChar <= 255))
	{
		MessageBox::Show("SOLO LETRAS", "ALERTA", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		e->Handled = true;
		return;
	}
}
private: System::Void btnAbrir_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Filter = "CSV Files|*.csv|TXT Files|*.txt|All Files|*";
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		string file = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
		LeerArchivo(file);
	}
}
};
}
