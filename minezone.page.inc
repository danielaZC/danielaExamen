<?php 
/**
 * Please do not commit to this project
 */

function minezone_page() {
	$nid = 52;
	//$nid = 48;
	$node = node_load($nid);

	$uid = $node->uid;
	$user = user_load($uid);



	dsm($user);
	dsm($node);

		
		$output = " ";
		$output .= '<h2>' . $node->title . '</h2>';
		$output .= "Tipo: " . ucfirst($node->type);
		$output .= '<br>';
		$output .= l("ver nodo", $node->nid);
		$output .= '<br>';
		$output .= "Fecha de creacion: " . format_date($node->created,'custom','d M Y');
 		$output .= '<br>';
 		if ($node->comment_count == 1) {

 			$output .= ("Cantidad de comentarios: Tiene 1 comentario.");
 		}
 		elseif ($node->comment_count == 0) {
 			$output .= ("Cantidad de comentarios: No tiene comentarios.");
 		}
 		else {
 			$output .= ("Cantidad de comentarios: Tiene " . $node->comment_count . "comentarios");
 		}

 		if ($node->status == 0){
 			$output .=  '<h4 style= "color: red">' . ("Estado: No publicado") . '</h4>';
 		}
 		else {
 			$output .= '<h4 style= "color: green">' . ("Estado: Publicado") . '</h4>';
 		}

 		$output .= "Creado por: " . $user->name . " ";
 		$output .= l($user->name, $user->name);
		return $output;
}
