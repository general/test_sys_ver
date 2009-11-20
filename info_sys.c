#include<gtk/gtk.h>

void add_call(GtkButton * button , gpointer data)
{
	g_print("add call\n");
	GtkWidget * dialog = gtk_dialog_new_with_buttons("add dialog",NULL,GTK_DIALOG_DESTROY_WITH_PARENT,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
	GtkWidget * table  = gtk_table_new(TRUE,2,2);
	GtkWidget * name = gtk_label_new("name:");
	GtkWidget * entry_name = gtk_entry_new();
	GtkWidget * entry_age  = gtk_entry_new();
	GtkWidget * age = gtk_label_new("age:");
	gtk_table_attach_defaults(GTK_TABLE(table),name,0,1,0,1);
	gtk_table_attach_defaults(GTK_TABLE(table),entry_name,1,2,0,1);
	gtk_table_attach_defaults(GTK_TABLE(table),age,0,1,1,2);
	gtk_table_attach_defaults(GTK_TABLE(table),entry_age,1,2,1,2);
	gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(dialog)->vbox),table);

	gtk_widget_show_all(dialog);
	gint res = gtk_dialog_run(GTK_DIALOG(dialog));
	switch(res)
	{
		case GTK_RESPONSE_OK:
			g_print("yes\n");
			const gchar * p_name = gtk_entry_get_text(GTK_ENTRY(entry_name));
			const gchar * p_age = gtk_entry_get_text(GTK_ENTRY(entry_age));
			g_printf("%s \t %s \n",p_name,p_age);
			break;
		case GTK_RESPONSE_CANCEL:
			g_print("no\n");
			break;
	}		


	gtk_widget_destroy(dialog);
}

	
	
	

void del_call(GtkButton * button , gpointer data)
{
	g_print("del_call\n");
}
void find_call(GtkButton * button ,gpointer data)
{
	g_print("find_call\n");
}

int main(int argc,char **argv)
{
	gtk_init(&argc,&argv);
	GtkWidget * window ;
	GtkWidget * vbox ;
	GtkWidget * bbox ;
	GtkWidget * img ;
	
	GtkWidget * add ;
	GtkWidget * del ;
	GtkWidget * find ;
	GtkWidget * quit ;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"info_system");
	gtk_window_set_default_size(GTK_WINDOW(window),400,300);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

	vbox = gtk_vbox_new(FALSE,4);
	bbox = gtk_hbutton_box_new();
	gtk_button_box_set_layout(GTK_BUTTON_BOX(bbox),GTK_BUTTONBOX_EDGE);

	add = gtk_button_new_with_label("add");
	del = gtk_button_new_with_label("del");
	find = gtk_button_new_with_label("find");
	quit = gtk_button_new_with_label("quit");

	gtk_box_pack_start(GTK_BOX(bbox),add,FALSE,FALSE,4);
	gtk_box_pack_start(GTK_BOX(bbox),del,FALSE,FALSE,4);
	gtk_box_pack_start(GTK_BOX(bbox),find,FALSE,FALSE,4);
	gtk_box_pack_start(GTK_BOX(bbox),quit,FALSE,FALSE,4);

	g_signal_connect(G_OBJECT(add),"clicked",G_CALLBACK(add_call),NULL);
	g_signal_connect(G_OBJECT(del),"clicked",G_CALLBACK(del_call),NULL);
	g_signal_connect(G_OBJECT(find),"clicked",G_CALLBACK(find_call),NULL);
	g_signal_connect(G_OBJECT(quit),"clicked",G_CALLBACK(gtk_main_quit),NULL);

	img = gtk_image_new_from_file("pic.jpg");

	gtk_box_pack_start(GTK_BOX(vbox),img,TRUE,TRUE,4);
	gtk_box_pack_start(GTK_BOX(vbox),bbox,FALSE,FALSE,4);

	gtk_container_add(GTK_CONTAINER(window),vbox);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}



