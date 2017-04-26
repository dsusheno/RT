/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_add_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:12:42 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/02 17:31:38 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	put_label_inside_box4(t_gtk *gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->l_limit, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->l_xmin, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->e_xmin, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->l_xmax, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box6), gtk->e_xmax, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->l_ymin, 0, 0, 45);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->e_ymin, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->l_ymax, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->e_ymax, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box7), gtk->l_info_limit, 0, 0, 45);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->l_zmin, 0, 0, 45);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->e_zmin, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->l_zmax, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box8), gtk->e_zmax, 0, 0, 0);
}

void	put_label_inside_box3(t_gtk *gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_box13), gtk->e_i, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box14), gtk->l_tr, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box14), gtk->e_tr, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box15), gtk->l_tex, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box15), gtk->c_tex, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->l_che1, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->e_che1, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->l_che2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->e_che2, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->l_che3, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->e_che3, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->l_square, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box16), gtk->e_square, 0, 0, 0);
	put_label_inside_box4(gtk);
}

void	put_label_inside_box2(t_gtk *gtk)
{
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_rot, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_x2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_rotx, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_y2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_roty, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->l_z2, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box5), gtk->e_rotz, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->l_color, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box9), gtk->e_color, 0, 0, 30);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box10), gtk->l_shine, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box10), gtk->e_shine, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box11), gtk->l_refrac, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box11), gtk->e_refrac, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->l_ka, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->e_ka, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->l_kd, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->e_kd, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->l_ks, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box12), gtk->e_ks, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box13), gtk->l_i, 0, 0, 10);
	put_label_inside_box3(gtk);
}

void	put_label_inside_box(t_gtk *gtk, int clicked)
{
	if (clicked == -10)
	{
		gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->l_obj, 0, 0, 10);
		gtk_box_pack_start(GTK_BOX(gtk->obj_box), gtk->c_obj, 0, 0, 0);
	}
	gtk_box_pack_start(GTK_BOX(gtk->obj_box2), gtk->l_nobj, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box2), gtk->e_nobj, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_pos, 0, 0, 11);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_x, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posx, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_y, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posy, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->l_z, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box3), gtk->e_posz, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_scale, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_x1, 0, 0, 17);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scalex, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_y1, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scaley, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->l_z1, 0, 0, 10);
	gtk_box_pack_start(GTK_BOX(gtk->obj_box4), gtk->e_scalez, 0, 0, 0);
	put_label_inside_box2(gtk);
}

void	put_box_inside_gbox(t_gtk *gtk, int clicked)
{
	if (clicked == -10)
		gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box2, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box3, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box4, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box5, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box6, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box7, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box8, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box9, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box10, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box11, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box12, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box13, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box14, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box15, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(gtk->obj_gbox), gtk->obj_box16, 0, 0, 0);
}
