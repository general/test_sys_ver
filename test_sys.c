#include<gtk/gtk.h>

GtkWidget * window ;
//GtkWidget * subwin ;

const gchar * big_img_file[6] = {"b1.jpg","b2.jpg","b3.jpg","b4.jpg","b5.jpg","b6.jpg"};

void img_call(GtkButton * button  ,gpointer data)
{
	gint s = 1; 
/*
	subwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"img");
	gtk_window_set_default_size(GTK_WINDOW(window),600,400);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_widget_destroy),subwin);
*/

	GtkWidget * dialog = gtk_dialog_new_with_buttons("img_show",NULL,GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
	gtk_dialog_set_has_separator(GTK_DIALOG(dialog),TRUE);

	GtkWidget * vbox ;
	GtkWidget * hbox1 ;
	GtkWidget * img  = gtk_image_new_from_file(big_img_file[s]);
	GtkWidget * frame = gtk_frame_new("菜品介绍");
	GtkWidget * label = gtk_label_new("this is an intrudution");
	gtk_container_add(GTK_CONTAINER(frame),label);

	gtk_box_pack_start(GTK_BOX(hbox1),img,TRUE,TRUE,4);
	gtk_box_pack_start(GTK_BOX(hbox1),frame,FALSE,FALSE,5);
	
	GtkWidget * entry = gtk_entry_new();
	GtkWidget * lb = gtk_label_new("请输入预定数量:");
	GtkWidget * hbox2 = gtk_hbox_new(FALSE,2);
	gtk_box_pack_start(GTK_BOX(hbox2),lb,FALSE,FALSE,4);
	gtk_box_pack_start(GTK_BOX(hbox2),entry,FALSE,FALSE,4);
/*

	GtkWidget * sure = gtk_button_new_with_label("确定");
	GtkWidget * cancel = gtk_button_new_with_label("取消");
	
	GtkWidget * hbox3 = gtk_hbox_new(FALSE,2);
	gtk_box_pack_start(GTK_BOX(hbox3),sure,FALSE,FALSE,4);
	gtk_box_pack_start(GTK_BOX(hbox3),cancel,FALSE,FALSE,4);
*/
	gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox1);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox2);
//	gtk_box_pack_start_defaults(GTK_BOX(vbox),hbox3);

	gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(dialog)->vbox),vbox);


	gtk_widget_show_all(dialog);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
		
}

int main(int argc,char **argv)
{
	GtkWidget * window ;
	GtkWidget * vbox ;

	GtkWidget * hbox1 ;
	GtkWidget * hbox2 ;

	GtkWidget * label ;

	GtkWidget * img[6] ;
	GtkWidget * eventbox[6] ;
	gchar * img_file[6] = {"1.jpg","2.jpg","3.jpg","4.jpg","5.jpg","6.jpg"};

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"system_test");
	gtk_window_set_default_size(GTK_WINDOW(window),600,400);
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

	hbox1 = gtk_hbox_new(TRUE,4);
	hbox2 = gtk_hbox_new(TRUE,4);
	vbox = gtk_vbox_new(FALSE,5);

	
	label = gtk_label_new("welcome to use my system !");
	
	gint i = 0 ;
	for( ; i<6; i++)
	{
		eventbox[i] = gtk_button_new();
		img[i] = gtk_image_new_from_file(img_file[i]);
		gtk_container_add(GTK_CONTAINER(eventbox[i]),img[i]);
		g_signal_connect(G_OBJECT(eventbox[i]),"clicked",G_CALLBACK(img_call),NULL);
	}

	i= 0;
	for( ; i<3; i++)
	{
		gtk_box_pack_start(GTK_BOX(hbox1),eventbox[i],FALSE,FALSE,4);
	}

	//i= 0;
	for( ; i<6; i++)
	{
		gtk_box_pack_start(GTK_BOX(hbox2),eventbox[i],FALSE,FALSE,4);
	}

	gtk_box_pack_start(GTK_BOX(vbox),hbox1,TRUE,TRUE,4);
	gtk_box_pack_start(GTK_BOX(vbox),hbox2,TRUE,TRUE,4);
	gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,4);

	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}








