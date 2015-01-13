// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "queryEmployeePage.h"
#include "Storage.h"
#define QUERY_BY_NAME 1
#define QUERY_BY_NUM 2

 PersonTable* QueryEmployeePage::table = NULL;
 Fl_Input* QueryEmployeePage::userNumIP = NULL;
 Fl_Input* QueryEmployeePage::userNameIP = NULL;
QueryEmployeePage::QueryEmployeePage() {

  { Fl_Double_Window* o = new Fl_Double_Window(541, 513, "\345\221\230\345\267\245\347\256\241\347\220\206");
    container = o;
    o->user_data((void*)(this));
    { 
		Fl_Box* o = new Fl_Box(45, 60, 465, 200);
		o->box(FL_THIN_UP_BOX);
		o->color((Fl_Color)76);
    } // Fl_Box* o
    { 
		userNameIP = new Fl_Input(129, 95, 200, 40, "\345\221\230\345\267\245\345\220\215\345\255\227\357\274\232");
    } // Fl_Input* o
    { 
		Fl_Button* bt = new Fl_Button(345, 95, 125, 45, "\346\214\211\345\220\215\345\255\227\346\237\245\350\257\242");
		bt->callback((Fl_Callback*)QueryEmployeePage::buttonCallBack,(void*)QUERY_BY_NAME);
    } // Fl_Button* o
    { 
		Fl_Box* o = new Fl_Box(195, 14, 119, 31, "\346\237\245\350\257\242\345\221\230\345\267\245");
		o->labelsize(32);
    } // Fl_Box* o
    { 
		userNumIP = new Fl_Input(129, 170, 200, 40, "\345\221\230\345\267\245\347\274\226\345\217\267\357\274\232");

    } // Fl_Input* o
    { 
		Fl_Button* bt = new Fl_Button(345, 170, 125, 45, "\346\214\211\347\274\226\345\217\267\346\237\245\350\257\242");
		bt->callback((Fl_Callback*)QueryEmployeePage::buttonCallBack,(void*)QUERY_BY_NUM);
    } // Fl_Button* o
    { 
		PersonTable* o = new PersonTable(45, 285, 465, 185);
		table = o;
		o->end();
    } // Fl_Table* o
    o->end();
  } // Fl_Double_Window* o
  initTable();
}

void QueryEmployeePage::show()
{
	container->show();
}

void QueryEmployeePage::buttonCallBack( Fl_Widget* sender, void* userdata )
{
	int buttonType = (int)userdata;
	Storage* storage = Storage::getInstance();
	if(buttonType == QUERY_BY_NAME)
	{
		table->setData(storage->queryPersonByName(userNameIP->value()));
	}
	else if (buttonType == QUERY_BY_NUM)
	{
		table->setData(storage->queryPersonByNum(userNumIP->value()));
	}
}

void QueryEmployeePage::initTable()
{
	table->cols(4);
	table->col_header(1);
	table->col_header_height(25);

	table->row_height_all(25);
	table->col_width_all(table->w()/4);
}


// Handle drawing all cells in table
void PersonTable::draw_cell(TableContext context, 
							int R, int C, int X, int Y, int W, int H)
{
	static char rowHeader[40];
	sprintf(rowHeader, "%d", R);		// text for each cell

	switch ( context )
	{
	case CONTEXT_STARTPAGE:
		fl_font(FL_HELVETICA, 16);
		return;

	case CONTEXT_COL_HEADER:
		fl_push_clip(X, Y, W, H);
		{
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
			fl_color(FL_RED);
			fl_draw(header[C], X, Y, W, H, FL_ALIGN_CENTER);
		}
		fl_pop_clip();
		return;

	case CONTEXT_ROW_HEADER:
		fl_push_clip(X, Y, W, H);
		{
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
			fl_color(FL_BLACK);
			fl_draw(rowHeader, X, Y, W, H, FL_ALIGN_CENTER);
		}
		fl_pop_clip();
		return;

	case CONTEXT_CELL:
		{
			fl_push_clip(X, Y, W, H);
			{
				// BG COLOR
				fl_color( row_selected(R) ? selection_color() : cell_bgcolor);
				fl_rectf(X, Y, W, H);

				// TEXT
				fl_color(cell_fgcolor);
				fl_draw(data.at(R).at(C).c_str(), X, Y, W, H, FL_ALIGN_CENTER);

				// BORDER
				fl_color(color()); 
				fl_rect(X, Y, W, H);
			}
			fl_pop_clip();
			return;
		}

	case CONTEXT_TABLE:
		fprintf(stderr, "TABLE CONTEXT CALLED\n");
		return;

	case CONTEXT_ENDPAGE:
	case CONTEXT_RC_RESIZE:
	case CONTEXT_NONE:
		return;
	}
}

// Callback whenever someone clicks on different parts of the table
void PersonTable::event_callback(Fl_Widget*, void *data)
{
	PersonTable *o = (PersonTable*)data;
	o->event_callback2();
}

void PersonTable::event_callback2()
{
	int R = callback_row(),
		C = callback_col();
	TableContext context = callback_context();
	printf("'%s' callback: ", (label() ? label() : "?"));
	printf("Row=%d Col=%d Context=%d Event=%d InteractiveResize? %d\n",
		R, C, (int)context, (int)Fl::event(), (int)is_interactive_resize());
}