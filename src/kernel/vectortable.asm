
	.global 	_reset_vector
	.global 	_interrupt_vector
	.set 		noreorder

	.section	.vector.reset
_reset_vector:
	la		$26, kinit
	jr		$26
	nop
	
	.section	.vector.interrupt	
_interrupt_vector:
	la		$26, kir_global_handler
	jr		$26
	nop

	.set reorder
