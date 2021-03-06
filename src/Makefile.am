# We define the global AM_CPPFLAGS as everything we compile includes from these
# directories.
AM_CPPFLAGS = \
	-I$(top_srcdir) -I$(top_srcdir)/include \
	-I$(top_builddir)/include $(F2C_CPPFLAGS)

#
# Main library
#
lib_LTLIBRARIES = libtensor.la

libtensor_la_SOURCES = \
	tools/tictoc.cc \
	tools/backtrace.cc \
	tools/jobs.cc \
	tools/jobs_save.cc \
	rand/rand.cc \
	indices/indices.cc \
	indices/concat.cc \
	indices/linspace_d.cc \
	indices/linspace_z.cc \
	indices/booleans.cc \
	indices/which.cc \
	sparse/full_d.cc \
	sparse/full_z.cc \
	sparse/sparse_d.cc \
	sparse/sparse_z.cc \
	sparse/sparse_d_to_z.cc \
	sparse/sparse_kron_d.cc \
	sparse/sparse_kron_z.cc \
	sparse/sparse_ops_d.cc \
	sparse/sparse_ops_z.cc \
	sparse/mmult_sparse_tensor_d.cc \
	sparse/mmult_sparse_tensor_z.cc \
	sparse/mmult_tensor_sparse_d.cc \
	sparse/mmult_tensor_sparse_z.cc \
	tensor/tensor_common.cc \
	tensor/tensor_d.cc \
	tensor/tensor_z.cc \
	tensor/tensor_to_complex.cc \
	tensor/tensor_conj.cc \
	tensor/tensor_imag_d.cc \
	tensor/tensor_real_z.cc \
	tensor/tensor_imag_z.cc \
	tensor/matrix_norminf_d.cc \
	tensor/matrix_norminf_z.cc \
	tensor/matrix_adjoint_z.cc \
	tensor/matrix_diag_d.cc \
	tensor/matrix_diag_z.cc \
	tensor/matrix_trace_d.cc \
	tensor/matrix_trace_z.cc \
	tensor/tensor_trace_d.cc \
	tensor/tensor_trace_z.cc \
	tensor/matrix_transpose_d.cc \
	tensor/matrix_transpose_z.cc \
	tensor/tensor_permute_d.cc \
	tensor/tensor_permute_z.cc \
	tensor/tensor_fold_d.cc \
	tensor/tensor_fold_z.cc \
	tensor/tensor_fold_dz.cc \
	tensor/tensor_foldin_d.cc \
	tensor/tensor_foldin_z.cc \
	tensor/tensor_kron_d.cc \
	tensor/tensor_kron_z.cc \
	tensor/tensor_sum_d.cc \
	tensor/tensor_sum_z.cc \
	tensor/tensor_norm0_d.cc \
	tensor/tensor_norm0_z.cc \
	tensor/tensor_norm2_d.cc \
	tensor/tensor_norm2_z.cc \
	tensor/tensor_scale_d.cc \
	tensor/tensor_scale_z.cc \
	tensor/tensor_sort_d.cc \
	tensor/tensor_squeeze.cc \
	tensor/tensor_squeeze_d.cc \
	tensor/tensor_squeeze_z.cc \
	tensor/tensor_take_diag_d.cc \
	tensor/tensor_take_diag_z.cc \
	compare/rtensor_rtensor_all_equal.cc \
	compare/rtensor_rtensor_e.cc \
	compare/rtensor_rtensor_l.cc \
	compare/rtensor_rtensor_g.cc \
	compare/rtensor_rtensor_le.cc \
	compare/rtensor_rtensor_ge.cc \
	compare/rtensor_rtensor_ne.cc \
	compare/rtensor_double_e.cc \
	compare/rtensor_double_l.cc \
	compare/rtensor_double_g.cc \
	compare/rtensor_double_le.cc \
	compare/rtensor_double_ge.cc \
	compare/rtensor_double_ne.cc \
	compare/ctensor_ctensor_all_equal.cc \
	compare/ctensor_ctensor_e.cc \
	compare/ctensor_ctensor_ne.cc \
	compare/ctensor_cdouble_e.cc \
	compare/ctensor_cdouble_ne.cc \
	compare/indices_indices_e.cc \
	compare/indices_indices_l.cc \
	compare/indices_indices_g.cc \
	compare/indices_indices_le.cc \
	compare/indices_indices_ge.cc \
	compare/indices_indices_ne.cc \
	compare/indices_index_e.cc \
	compare/indices_index_l.cc \
	compare/indices_index_g.cc \
	compare/indices_index_le.cc \
	compare/indices_index_ge.cc \
	compare/indices_index_ne.cc \
	generated/tensor_unop_abs_d.cc \
	generated/tensor_unop_sqrt_d.cc \
	generated/tensor_unop_exp_d.cc \
	generated/tensor_unop_cos_d.cc \
	generated/tensor_unop_sin_d.cc \
	generated/tensor_unop_tan_d.cc \
	generated/tensor_unop_cosh_d.cc \
	generated/tensor_unop_sinh_d.cc \
	generated/tensor_unop_tanh_d.cc \
	generated/tensor_unop_abs_z.cc \
	generated/tensor_unop_cos_z.cc \
	generated/tensor_unop_sin_z.cc \
	generated/tensor_unop_tan_z.cc \
	generated/tensor_unop_cosh_z.cc \
	generated/tensor_unop_sinh_z.cc \
	generated/tensor_unop_tanh_z.cc \
	generated/tensor_unop_exp_z.cc \
	generated/tensor_unop_sqrt_z.cc \
	linalg/eig_d.cc \
	linalg/eig_z.cc \
	linalg/svd_d.cc \
	linalg/svd_z.cc \
	linalg/solve_d.cc \
	linalg/solve_z.cc \
	linalg/expm_d.cc \
	linalg/expm_z.cc \
	linalg/eig_power_d.cc \
	linalg/eig_power_z.cc \
	linalg/eig_sym_d.cc \
	linalg/eig_sym_z.cc \
	views/range.cc \
	sdf/data_file.cc \
	sdf/idata_file.cc \
	sdf/odata_file.cc

arpack_ng_src =					\
	../arpack-ng/sgetv0.f			\
	../arpack-ng/slaqrb.f			\
	../arpack-ng/sstqrb.f			\
	../arpack-ng/ssortc.f			\
	../arpack-ng/ssortr.f			\
	../arpack-ng/sstatn.f			\
	../arpack-ng/sstats.f			\
	../arpack-ng/snaitr.f			\
	../arpack-ng/snapps.f			\
	../arpack-ng/snaup2.f			\
	../arpack-ng/snaupd.f			\
	../arpack-ng/snconv.f			\
	../arpack-ng/sneigh.f			\
	../arpack-ng/sngets.f			\
	../arpack-ng/ssaitr.f			\
	../arpack-ng/ssapps.f			\
	../arpack-ng/ssaup2.f			\
	../arpack-ng/ssaupd.f			\
	../arpack-ng/ssconv.f			\
	../arpack-ng/sseigt.f			\
	../arpack-ng/ssgets.f			\
	../arpack-ng/sneupd.f			\
	../arpack-ng/sseupd.f			\
	../arpack-ng/ssesrt.f			\
	../arpack-ng/dgetv0.f			\
	../arpack-ng/dlaqrb.f			\
	../arpack-ng/dstqrb.f			\
	../arpack-ng/dsortc.f			\
	../arpack-ng/dsortr.f			\
	../arpack-ng/dstatn.f			\
	../arpack-ng/dstats.f			\
	../arpack-ng/dnaitr.f			\
	../arpack-ng/dnapps.f			\
	../arpack-ng/dnaup2.f			\
	../arpack-ng/dnaupd.f			\
	../arpack-ng/dnconv.f			\
	../arpack-ng/dneigh.f			\
	../arpack-ng/dngets.f			\
	../arpack-ng/dsaitr.f			\
	../arpack-ng/dsapps.f			\
	../arpack-ng/dsaup2.f			\
	../arpack-ng/dsaupd.f			\
	../arpack-ng/dsconv.f			\
	../arpack-ng/dseigt.f			\
	../arpack-ng/dsgets.f			\
	../arpack-ng/dneupd.f			\
	../arpack-ng/dseupd.f			\
	../arpack-ng/dsesrt.f			\
	../arpack-ng/cnaitr.f			\
	../arpack-ng/cnapps.f			\
	../arpack-ng/cnaup2.f			\
	../arpack-ng/cnaupd.f			\
	../arpack-ng/cneigh.f			\
	../arpack-ng/cneupd.f			\
	../arpack-ng/cngets.f			\
	../arpack-ng/cgetv0.f			\
	../arpack-ng/csortc.f			\
	../arpack-ng/cstatn.f			\
	../arpack-ng/znaitr.f			\
	../arpack-ng/znapps.f			\
	../arpack-ng/znaup2.f			\
	../arpack-ng/znaupd.f			\
	../arpack-ng/zneigh.f			\
	../arpack-ng/zneupd.f			\
	../arpack-ng/zngets.f			\
	../arpack-ng/zgetv0.f			\
	../arpack-ng/zsortc.f			\
	../arpack-ng/zstatn.f
arpack_ng_util =				\
	../arpack-ng/icnteq.f			\
	../arpack-ng/icopy.f			\
	../arpack-ng/iset.f			\
	../arpack-ng/iswap.f			\
	../arpack-ng/ivout.f			\
	../arpack-ng/second_NONE.f		\
	../arpack-ng/svout.f			\
	../arpack-ng/smout.f			\
	../arpack-ng/dvout.f			\
	../arpack-ng/dmout.f			\
	../arpack-ng/cvout.f			\
	../arpack-ng/cmout.f			\
	../arpack-ng/zvout.f			\
	../arpack-ng/zmout.f
if TENSOR_ARPACK
libtensor_la_SOURCES +=				\
	arpack/arpack_d.cc			\
	arpack/arpack_z.cc			\
	arpack/eigs_d.cc			\
	arpack/eigs_z.cc			\
	$(arpack_ng_src) $(arpack_ng_util)
libtensor_la_LDFLAGS = $(FLIBS)
endif
AM_FFLAGS = $(FFLAGS)
if USE_F2C
libtensor_la_SOURCES += ../arpack-ng/common.cc
AM_FFLAGS += -E
endif

itebd_expected_slow = \
	mps/iTEBD/itebd_slow_expected_d.cc \
	mps/iTEBD/itebd_slow_expected_z.cc \
	mps/iTEBD/itebd_slow_expected2_d.cc \
	mps/iTEBD/itebd_slow_expected2_z.cc \
	mps/iTEBD/itebd_slow_string_order_d.cc \
	mps/iTEBD/itebd_slow_string_order_z.cc \
	mps/iTEBD/itebd_slow_expected12_d.cc \
	mps/iTEBD/itebd_slow_expected12_z.cc
itebd_expected_wrong = \
	mps/iTEBD/itebd_expected1_d.cc \
	mps/iTEBD/itebd_expected1_z.cc \
	mps/iTEBD/itebd_expected2_d.cc \
	mps/iTEBD/itebd_expected2_z.cc \
	mps/iTEBD/itebd_string_order_d.cc \
	mps/iTEBD/itebd_string_order_z.cc \
	mps/iTEBD/itebd_expected12_d.cc \
	mps/iTEBD/itebd_expected12_z.cc

if BUILD_MPS

lib_LTLIBRARIES += libmps.la

libmps_la_SOURCES = \
	mps/quantum/spin.cc \
	mps/quantum/fock.cc \
	mps/quantum/decompose_operator_d.cc \
	mps/quantum/decompose_operator_z.cc \
	mps/quantum/sparse_1d_hamiltonian_d.cc \
	mps/quantum/sparse_1d_hamiltonian_z.cc \
	mps/quantum/sparse_1d_hamiltonian_many_d.cc \
	mps/quantum/sparse_1d_hamiltonian_many_z.cc \
	mps/hamiltonian/hamiltonian.cc \
	mps/hamiltonian/hamiltonian_expected_d.cc \
	mps/hamiltonian/hamiltonian_expected_z.cc \
	mps/hamiltonian/sparse_hamiltonian.cc \
	mps/hamiltonian/hamiltonian_ti.cc \
	mps/hamiltonian/hamiltonian_constant.cc \
	mps/hamiltonian/split_interaction.cc \
	mps/tools/entropy.cc \
	mps/tools/truncate.cc \
	mps/tools/limited_svd_d.cc \
	mps/tools/limited_svd_z.cc \
	mps/tools/build_E_matrix_d.cc \
	mps/tools/build_E_matrix_z.cc \
	mps/tools/propagate_mps_d.cc \
	mps/tools/propagate_mps_z.cc \
	mps/iTEBD/itebd_d.cc \
	mps/iTEBD/itebd_z.cc \
	mps/iTEBD/itebd_itime_d.cc \
	mps/iTEBD/itebd_itime_z.cc \
	mps/iTEBD/itebd_ghz_state.cc \
	mps/iTEBD/itebd_cluster_state.cc \
	mps/iTEBD/itebd_aklt_state.cc \
	$(itebd_expected_slow) \
	mps/iTEBD/itebd_energy_d.cc \
	mps/iTEBD/itebd_energy_z.cc \
	mps/mps/rmps.cc \
	mps/mps/rmps_random.cc \
	mps/mps/rmps_product_state.cc \
	mps/mps/rmps_ghz_state.cc \
	mps/mps/rmps_cluster_state.cc \
	mps/mps/rmps_to_vector.cc \
	mps/mps/cmps.cc \
	mps/mps/cmps_random.cc \
	mps/mps/cmps_from_rmps.cc \
	mps/mps/cmps_product_state.cc \
	mps/mps/cmps_to_vector.cc \
	mps/mps/mps_prop_matrix_d.cc \
	mps/mps/mps_prop_matrix_z.cc \
	mps/mps/mps_norm_d.cc \
	mps/mps/mps_norm_z.cc \
	mps/mps/mps_scprod_d.cc \
	mps/mps/mps_scprod_z.cc \
	mps/mps/mps_expected1_d.cc \
	mps/mps/mps_expected1_dz.cc \
	mps/mps/mps_expected1_z.cc \
	mps/mps/mps_expected2_d.cc \
	mps/mps/mps_expected2_dz.cc \
	mps/mps/mps_expected2_z.cc \
	mps/mps/mps_simplify_d.cc \
	mps/mps/mps_simplify_z.cc \
	mps/mps/apply_local_operator_d.cc \
	mps/mps/apply_local_operator_z.cc
#	mps/dmrg/rdmrg.cc
#	mps/dmrg/cdmrg.cc
endif

generated/tensor_unop_%_d.cc: tensor/tensor_unop.cc Makefile
	k=`echo $@ | sed 's,.*unop_\(.*\)_d.cc,\1,g'`;\
	sed -e "s,TYPE[12],Tensor<double>,g;s,OPERATOR1,$$k,;s,OPERATOR2,std::$$k,g" $< > $@
generated/tensor_unop_%_z.cc: tensor/tensor_unop.cc Makefile
	k=`echo $@ | sed 's,.*unop_\(.*\)_z.cc,\1,g'`;\
	sed -e "s,TYPE[12],Tensor<cdouble>,g;s,OPERATOR1,$$k,;s,OPERATOR2,std::$$k,g" $< > $@
generated/tensor_unop_abs_d.cc: tensor/tensor_unop.cc Makefile
	sed -e "s,TYPE1,Tensor<double>,g;s,TYPE2,Tensor<double>,g;s,OPERATOR1,abs,;s,OPERATOR2,std::abs,g" $< > $@
generated/tensor_unop_abs_z.cc: tensor/tensor_unop.cc Makefile
	sed -e "s,TYPE1,Tensor<cdouble>,g;s,TYPE2,Tensor<double>,g;s,OPERATOR1,abs,;s,OPERATOR2,std::abs,g" $< > $@

if HAVE_64BITS
libtensor_la_SOURCES += rand/rand64.cc
else
libtensor_la_SOURCES += rand/rand32.cc
endif
