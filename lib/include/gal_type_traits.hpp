#ifndef GALLIBRARY_TYPE_TRAITS_HPP
#define GALLIBRARY_TYPE_TRAITS_HPP

#include <type_traits>

namespace gal
{
	namespace impl
	{
		namespace detail
		{
			template<typename... T>
			using wrapper = std::tuple<T...>;

			// wrapper_impl<type1, type2, type3...>
			template<typename... T>
			struct wrapper_impl
			{
				using type = wrapper<T...>;
			};

			// wrapper_impl<type>
			template<typename T>
			struct wrapper_impl<T>
			{
				using type = wrapper<T>;
			};

			// wrapper_impl<>
			template<>
			struct wrapper_impl<>
			{
				using type = wrapper<>;
			};

			// wrapper_impl<wrapper<type1, type2, type3...>>
			template<typename... T>
			struct wrapper_impl<wrapper<T...>>
			{
				using type = wrapper<T...>;
			};

			// wrapper_impl<wrapper<type1, type2, type3...>, wrapper<type11, type22, type33>...>
			template<typename... T1, typename... T2, typename... More>
			struct wrapper_impl<std::tuple<T1...>, std::tuple<T2...>, More...>
			{
				using type = typename wrapper_impl<std::tuple<T1..., T2...>, More...>::type;
			};


		}

		template<typename... T>
		using wrapper = typename detail::wrapper_impl<T...>::type;
		template<typename... T>
		using wrap_catter = typename detail::wrapper_impl<wrapper<T>...>::type;//decltype(std::tuple_cat(std::declval<wrapper<T>>()...));


		template<typename T>
		using remove_const = std::remove_const<T>;
		template<typename T>
		using add_const = std::add_const<T>;

		template<typename T>
		using remove_volatile = std::remove_volatile<T>;
		template<typename T>
		using add_volatile = std::add_volatile<T>;

		template<typename T>
		using remove_pointer = std::remove_pointer<T>;
		template<typename T>
		using add_pointer = std::add_pointer<T>;

		template<typename T>
		using remove_reference = std::remove_reference<T>;
		template<typename T>
		using add_lvalue_reference = std::add_lvalue_reference<T>;
		template<typename T>
		using add_rvalue_reference = std::add_rvalue_reference<T>;

		template<typename T, typename U>
		using is_same = std::is_same<T, U>;

		template<typename Base, typename Derived>
		using is_base_of = std::is_base_of<Base, Derived>;

		template<typename From, typename To>
		using is_convertible = std::is_convertible<From, To>;

		template<typename Func, typename... Args>
		using is_invocable = std::is_invocable<Func, Args...>;
		template<typename Func, typename... Args>
		using is_nothrow_invocable = std::is_nothrow_invocable<Func, Args...>;
		template<typename Ret, typename Func, typename... Args>
		using is_invocable_r = std::is_invocable_r<Ret, Func, Args...>;
		template<typename Ret, typename Func, typename... Args>
		using is_nothrow_invocable_r = std::is_nothrow_invocable_r<Ret, Func, Args...>;

		template<typename T>
		using is_void = std::is_void<T>;

		template<typename T>
		using is_null_pointer = std::is_null_pointer<T>;

		template<typename T>
		using is_integral = std::is_integral<T>;

		template<typename T>
		using is_floating_point = std::is_floating_point<T>;

		template<typename T>
		using is_enum = std::is_enum<T>;

		template<typename T>
		using is_union = std::is_union<T>;

		template<typename T>
		using is_class = std::is_class<T>;

		template<typename T>
		using is_function = std::is_function<T>;

		template<typename T>
		using is_pointer = std::is_pointer<T>;

		template<typename T>
		using is_lvalue_reference = std::is_lvalue_reference<T>;

		template<typename T>
		using is_rvalue_reference = std::is_rvalue_reference<T>;

		template<typename T>
		using is_member_object_pointer = std::is_member_object_pointer<T>;

		template<typename T>
		using is_member_function_pointer = std::is_member_function_pointer<T>;

		template<typename T>
		using is_fundamental = std::is_fundamental<T>;

		template<typename T>
		using is_arithmetic = std::is_arithmetic<T>;

		template<typename T>
		using is_scalar = std::is_scalar<T>;

		template<typename T>
		using is_object = std::is_object<T>;

		template<typename T>
		using is_compound = std::is_compound<T>;

		template<typename T>
		using is_reference = std::is_reference<T>;

		template<typename T>
		using is_member_pointer = std::is_member_pointer<T>;

		template<typename T>
		using is_const = std::is_const<T>;

		template<typename T>
		using is_volatile = std::is_volatile<T>;

		template<typename T>
		using is_trivial = std::is_trivial<T>;

		template<typename T>
		using is_trivially_copyable = std::is_trivially_copyable<T>;

		template<typename T>
		using is_standard_layour = std::is_standard_layout<T>;

		template<typename T>
		using has_unique_object_representations = std::has_unique_object_representations<T>;

		template<typename T>
		using is_empty = std::is_empty<T>;

		template<typename T>
		using is_polymorphic = std::is_polymorphic<T>;

		template<typename T>
		using is_abstract = std::is_abstract<T>;

		template<typename T>
		using is_final = std::is_final<T>;

		template<typename T>
		using is_aggregate = std::is_aggregate<T>;

		template<typename T>
		using is_signed = std::is_signed<T>;

		template<typename T>
		using is_unsigned = std::is_unsigned<T>;

		template<typename T, typename... Args>
		using is_constructible = std::is_constructible<T, Args...>;
		template<typename T, typename... Args>
		using is_trivially_constructible = std::is_trivially_constructible<T, Args...>;
		template<typename T, typename... Args>
		using is_nothrow_constructible = std::is_nothrow_constructible<T, Args...>;

		template<typename T>
		using is_default_constructible = std::is_default_constructible<T>;
		template<typename T>
		using is_trivially_default_constructible = std::is_trivially_default_constructible<T>;
		template<typename T>
		using is_nothrow_default_constructible = std::is_nothrow_default_constructible<T>;

		template<typename T>
		using is_copy_constructible = std::is_copy_constructible<T>;
		template<typename T>
		using is_trivially_copy_constructible = std::is_trivially_copy_constructible<T>;
		template<typename T>
		using is_nothrow_copy_constructible = std::is_nothrow_copy_constructible<T>;

		template<typename T>
		using is_move_constructible = std::is_move_constructible<T>;
		template<typename T>
		using is_trivially_move_constructible = std::is_trivially_move_constructible<T>;
		template<typename T>
		using is_nothrow_move_constructible = std::is_nothrow_move_constructible<T>;

		template<typename T, typename U>
		using is_assignable = std::is_assignable<T, U>;
		template<typename T, typename U>
		using is_trivially_assignable = std::is_trivially_assignable<T, U>;
		template<typename T, typename U>
		using is_nothrow_assignable = std::is_nothrow_assignable<T, U>;

		template<typename T>
		using is_copy_assignable = std::is_copy_assignable<T>;
		template<typename T>
		using is_trivially_copy_assignable = std::is_trivially_copy_assignable<T>;
		template<typename T>
		using is_nothrow_copy_assignable = std::is_nothrow_copy_assignable<T>;

		template<typename T>
		using is_move_assignable = std::is_move_assignable<T>;
		template<typename T>
		using is_trivially_move_assignable = std::is_trivially_move_assignable<T>;
		template<typename T>
		using is_nothrow_move_assignable = std::is_nothrow_move_assignable<T>;

		template<typename T>
		using is_destructible = std::is_destructible<T>;
		template<typename T>
		using is_trivially_destructible = std::is_trivially_destructible<T>;
		template<typename T>
		using is_nothrow_destructible = std::is_nothrow_destructible<T>;

		template<typename T>
		using has_virtual_destructor = std::has_virtual_destructor<T>;

		template<typename T, typename U>
		using is_swappable_with = std::is_swappable_with<T, U>;
		template<typename T>
		using is_swappable = std::is_swappable<T>;
		template<typename T, typename U>
		using is_nothrow_swappable_with = std::is_nothrow_swappable_with<T, U>;
		template<typename T>
		using is_nothrow_swappable = std::is_nothrow_swappable<T>;
	}

	/*
	 * template parameter pack
	 *
	 * for type:
	 *      cannot create a type that is itself a parameter pack(like using type = pack...)
	 *      if you need to extract the types, you can pull them out of the tuple
	 *      better has a template specialization for impl::wrapper(for nested type)
	 *
	 * for value:
	 *      better has a template specialization for impl::wrapper(for type above)
	 */

	/*
	 * for template<typename T, typename... More> struct Foo;
	 *      Foo<const type1, const type2, const type3...>
	 *          -> wrap_type<type1, type2, type3...>::type
	 * for template<typename T> struct Foo<T>;
	 *      Foo<type>
	 *          -> wrap_type<type>::type
	 * for template<typename T, typename... More> struct Foo<wrap_type<T, More...>>
	 *      Foo<wrap_type<type1, type2, type3...>>
	 *          -> wrap_type<type1, type2, type3...>::type
	 *
	 * for Foo<type1, type2, wrap_type<type3, type4>, type5, wrap_type<type6>>
	 *          -> Foo<type1, type2, type[34], type5, type[6]>
	 *          -> Foo<type1> -> type1
	 *          -> Foo<type2> -> type2
	 *          -> Foo<type[34]> -> type3, type4
	 *          -> Foo<type5> -> type5
	 *          -> Foo<type[6]> -> type6
	 *          -> wrap_type<...>
	 *          -> Foo<type1, type2, type3, type4, type5, type6>
	 *      for wrap detail, see impl::wrapper and impl::wrap_catter
	 */

	// wrapper
	template<typename... T>
	struct wrap_type
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = impl::wrap_catter<T...>;
	};

	// wrapper supporter
	template<typename... T>
	using wrap_type_t = typename wrap_type<T...>::type;

	template<typename T, typename... More>
	struct remove_const
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename remove_const<T>::type, typename remove_const<More...>::type>::type;
	};

	template<typename T>
	struct remove_const<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::remove_const<T>::type;
	};

	template<typename T, typename... More>
	struct remove_const<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_const<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_const
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename add_const<T>::type, typename add_const<More...>::type>::type;
	};

	template<typename T>
	struct add_const<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::add_const<T>::type;
	};

	template<typename T, typename... More>
	struct add_const<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_const<T, More...>::type;
	};

	template<typename T, typename... More>
	struct remove_volatile
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename remove_volatile<T>::type, typename remove_volatile<More...>::type>::type;
	};

	template<typename T>
	struct remove_volatile<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::remove_volatile<T>::type;
	};

	template<typename T, typename... More>
	struct remove_volatile<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_volatile<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_volatile
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename add_volatile<T>::type, typename add_volatile<More...>::type>::type;
	};

	template<typename T>
	struct add_volatile<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::add_volatile<T>::type;
	};

	template<typename T, typename... More>
	struct add_volatile<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_volatile<T, More...>::type;
	};

	template<typename T, typename... More>
	struct remove_pointer
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename remove_pointer<T>::type, typename remove_pointer<More...>::type>::type;
	};

	template<typename T>
	struct remove_pointer<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::remove_pointer<T>::type;
	};

	template<typename T, typename... More>
	struct remove_pointer<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_pointer<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_pointer
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename add_pointer<T>::type, typename add_pointer<More...>::type>::type;
	};

	template<typename T>
	struct add_pointer<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::add_pointer<T>::type;
	};

	template<typename T, typename... More>
	struct add_pointer<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_pointer<T, More...>::type;
	};

	template<typename T, typename... More>
	struct remove_reference
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename remove_reference<T>::type, typename remove_reference<More...>::type>::type;
	};

	template<typename T>
	struct remove_reference<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::remove_reference<T>::type;
	};

	template<typename T, typename... More>
	struct remove_reference<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_reference<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_lvalue_reference
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename add_lvalue_reference<T>::type, typename add_lvalue_reference<More...>::type>::type;
	};

	template<typename T>
	struct add_lvalue_reference<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::add_lvalue_reference<T>::type;
	};

	template<typename T, typename... More>
	struct add_lvalue_reference<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_lvalue_reference<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_rvalue_reference
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename wrap_type<typename add_rvalue_reference<T>::type, typename add_rvalue_reference<More...>::type>::type;
	};

	template<typename T>
	struct add_rvalue_reference<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename impl::add_rvalue_reference<T>::type;
	};

	template<typename T, typename... More>
	struct add_rvalue_reference<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_rvalue_reference<T, More...>::type;
	};

	template<typename T, typename... More>
	struct remove_cv
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_const<typename remove_volatile<T, More...>::type>::type;
	};

	template<typename T>
	struct remove_cv<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_const<typename remove_volatile<T>::type>::type;
	};

	template<typename T, typename... More>
	struct remove_cv<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_cv<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_cv
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_const<typename add_volatile<T, More...>::type>::type;
	};

	template<typename T>
	struct add_cv<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_const<typename add_volatile<T>::type>::type;
	};

	template<typename T, typename... More>
	struct add_cv<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv<T, More...>::type;
	};

	template<typename T, typename... More>
	struct remove_cv_ref
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_cv<typename remove_reference<T, More...>::type>::type;;
	};

	template<typename T>
	struct remove_cv_ref<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_cv<typename remove_reference<T>::type>::type;
	};

	template<typename T, typename... More>
	struct remove_cv_ref<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename remove_cv_ref<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_cv_lref
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv<typename add_lvalue_reference<T, More...>::type>::type;;
	};

	template<typename T>
	struct add_cv_lref<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv<typename add_lvalue_reference<T>::type>::type;
	};

	template<typename T, typename... More>
	struct add_cv_lref<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv_lref<T, More...>::type;
	};

	template<typename T, typename... More>
	struct add_cv_rref
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv<typename add_rvalue_reference<T, More...>::type>::type;;
	};

	template<typename T>
	struct add_cv_rref<T>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv<typename add_rvalue_reference<T>::type>::type;
	};

	template<typename T, typename... More>
	struct add_cv_rref<wrap_type<T, More...>>
	{
		using type [[maybe_unused]]/*The noisy IDE cannot find where it is used*/ = typename add_cv_rref<T, More...>::type;
	};

	template<typename T, typename... More>
	using remove_const_t = typename remove_const<T, More...>::type;
	template<typename T, typename... More>
	using remove_volatile_t = typename remove_volatile<T, More...>::type;
	template<typename T, typename... More>
	using remove_pointer_t = typename remove_pointer<T, More...>::type;
	template<typename T, typename... More>
	using remove_reference_t = typename remove_reference<T, More...>::type;
	template<typename T, typename... More>
	using remove_cv_t = typename remove_cv<T, More...>::type;
	template<typename T, typename... More>
	using remove_cv_ref_t = typename remove_cv_ref<T, More...>::type;

	template<typename T, typename... More>
	using add_const_t = typename add_const<T, More...>::type;
	template<typename T, typename... More>
	using add_volatile_t = typename add_volatile<T, More...>::type;
	template<typename T, typename... More>
	using add_pointer_t = typename add_pointer<T, More...>::type;
	template<typename T, typename... More>
	using add_lvalue_reference_t = typename add_lvalue_reference<T, More...>::type;
	template<typename T, typename... More>
	using add_rvalue_reference_t = typename add_rvalue_reference<T, More...>::type;
	template<typename T, typename... More>
	using add_cv_t = typename add_cv<T, More...>::type;
	template<typename T, typename... More>
	using add_cv_lref_t = typename add_cv_lref<T, More...>::type;
	template<typename T, typename... More>
	using add_cv_rref_t = typename add_cv_rref<T, More...>::type;

	/*
	 * for template<typename U, typename T, typename... More> struct Bar
	 *      Bar<type, type1, type2, type3...>
	 *          type1 -> type && type2 -> type && type3 ->type && ...
	 * for template<typename U, typename T> struct Bar<U, T>
	 *      Bar<type1, type2>
	 *          type2 -> type1
	 * for template<typename U, typename T, typename... More> struct Bar<U, wrap_type<T, More...>>
	 *      Bar<type, wrap_type<type1, type2, type3...>>
	 *          type1 -> type && type2 -> type && type3 -> type && ...
	 * for template<typename U, typename... Us, template T, typename... Ts> struct <wrap_type<U, Us...>, wrap_type<T, Ts...>>
	 *      Bar<wrap_type<type1, type2, type3...>, wrap_type<type11, type22, type33...>>
	 *          type11 -> type1 && type22 -> type2 && type33 -> type3 && ...
	 *
	 *      use U and T just for avoid ambiguous template instantiation for 3 args call
	 *      Bar<int, wrap_type<int, double>> can call
	 *      Bar<U, wrap_type<T, More...>> or Bar<wrap_type<Us...>, wrap_type<Ts...>>
	 *
	 * for Bar<type, type1, type2, wrap_type<type3, type4>, type5, wrap_type<type6>>
	 *          -> Bar<type1, type2, type[34], type5, type[6]>
	 *          -> Bar<type1> -> type1 -> type
	 *          -> Bar<type2> -> type2 -> type
	 *          -> Bar<type[34]> -> type3 -> type && type4 -> type
	 *          -> Bar<type5> -> type5 -> type
	 *          -> Bar<type[6]> -> type6 -> type
	 *          -> logical_and<...>
	 *          -> Bar<type, type1, type2, type3, type4, type5, type6>
	 */

	// is_same<U, type1, type2, type3...>
	template<typename U, typename T, typename... More>
	struct is_same
	{
		constexpr static bool value = is_same<U, T>::value && is_same<U, More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	// is_same<U, T>
	template<typename U, typename T>
	struct is_same<U, T>
	{
		constexpr static bool value = impl::is_same<T, U>::value;
	};

	// is_same<U, wrap_type<type1, type2, type3...>>
	template<typename U, typename T, typename... More>
	struct is_same<U, wrap_type<T, More...>>
	{
		constexpr static bool value = is_same<U, T, More...>::value;
	};

	// is_same<wrap_type<type1, type2, type3...>, T>
	template<typename U, typename... Us, typename T>
	struct is_same<wrap_type<U, Us...>, T>
	{
		// todo: test *
		constexpr static bool value = is_same<U, T>::value && is_same<Us..., T>::value;
	};

	// is_same<wrap_type<type1, type2, type3...>, wrap_type<type11, type22, type33...>>
	template<typename U, typename... Us, typename T, typename... Ts>
	struct is_same<wrap_type<U, Us...>, wrap_type<T, Ts...>>
	{
		// todo: test **
		constexpr static bool value = is_same<U, T>::value && (is_same<Us, Ts>::value && ...);
	};

	template<typename Base, typename Derived, typename... More>
	struct is_base_of
	{
		constexpr static bool value = is_base_of<Base, Derived>::value && is_base_of<Base, More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename Base, typename Derived>
	struct is_base_of<Base, Derived>
	{
		constexpr static bool value = impl::is_base_of<Base, Derived>::value;
	};

	template<typename Base, typename Derived, typename... More>
	struct is_base_of<Base, wrap_type<Derived, More...>>
	{
		constexpr static bool value = is_base_of<Base, Derived, More...>::value;
	};

	template<typename Base, typename... Bases, typename Derived>
	struct is_base_of<wrap_type<Base, Bases...>, Derived>
	{
		// todo: test *
		constexpr static bool value = is_base_of<Base, Derived>::value && is_base_of<Bases..., Derived>::value;
	};

	template<typename Base, typename... Bases, typename Derived, typename... Deriveds>
	struct is_base_of<wrap_type<Base, Bases...>, wrap_type<Derived, Deriveds...>>
	{
		// todo: test **
		constexpr static bool value = is_base_of<Base, Derived>::value && (is_base_of<Bases, Deriveds>::value && ...);
	};

	template<typename From, typename To, typename... More>
	struct is_convertible
	{
		constexpr static bool value = is_convertible<From, To>::value && is_convertible<From, More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename From, typename To>
	struct is_convertible<From, To>
	{
		constexpr static bool value = impl::is_convertible<From, To>::value;
	};

	template<typename From, typename To, typename... More>
	struct is_convertible<From, wrap_type<To, More...>>
	{
		constexpr static bool value = is_convertible<From, To, More...>::value;
	};

	template<typename From, typename... Froms, typename To>
	struct is_convertible<wrap_type<From, Froms...>, To>
	{
		// todo: test *
		constexpr static bool value = is_convertible<From, To>::value && is_convertible<Froms..., To>::value;
	};

	template<typename From, typename... Froms, typename To, typename... Tos>
	struct is_convertible<wrap_type<From, Froms...>, wrap_type<To, Tos...>>
	{
		// todo: test **
		constexpr static bool value = is_convertible<From, To>::value && (is_convertible<Froms, Tos>::value && ...);
	};

	template<typename Func, typename Arg, typename... Args>
	struct is_invocable
	{
		constexpr static bool value = is_invocable<Func, Arg>::value && is_invocable<Func, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename Func, typename Arg>
	struct is_invocable<Func, Arg>
	{
		constexpr static bool value = impl::is_invocable<Func, Arg>::value;
	};

	template<typename Func, typename... Args>
	struct is_invocable<Func, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_invocable<Func, Args...>::value;
	};

	template<typename Func, typename... Funcs, typename... Args>
	struct is_invocable<wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_invocable<Func, Args...>::value && is_invocable<Funcs..., Args...>::value;
	};

	template<typename Func, typename... Funcs, typename Arg>
	struct is_invocable<wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_invocable<Func, Arg>::value && is_invocable<Funcs..., Arg>::value;
	};

	template<typename Func, typename... Funs, typename Arg, typename... Args>
	struct is_invocable<wrap_type<Func, Funs...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_invocable<Func, Arg>::value && (is_invocable<Funs, Args>::value && ...);
	};

	template<typename Func, typename Arg, typename... Args>
	struct is_nothrow_invocable
	{
		constexpr static bool value = is_nothrow_invocable<Func, Arg>::value && is_nothrow_invocable<Func, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename Func, typename... Args>
	struct is_nothrow_invocable<Func, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_nothrow_invocable<Func, Args...>::value;
	};

	template<typename Func, typename Arg>
	struct is_nothrow_invocable<Func, Arg>
	{
		constexpr static bool value = impl::is_nothrow_invocable<Func, Arg>::value;
	};

	template<typename Func, typename... Funcs, typename... Args>
	struct is_nothrow_invocable<wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_nothrow_invocable<Func, Args...>::value && is_nothrow_invocable<Funcs..., Args...>::value;
	};

	template<typename Func, typename... Funcs, typename Arg>
	struct is_nothrow_invocable<wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_invocable<Func, Arg>::value && is_nothrow_invocable<Funcs..., Arg>::value;
	};

	template<typename Func, typename... Funcs, typename Arg, typename... Args>
	struct is_nothrow_invocable<wrap_type<Func, Funcs...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_invocable<Func, Arg>::value && (is_nothrow_invocable<Funcs, Args>::value && ...);
	};

	template<typename Ret, typename Func, typename Arg, typename... Args>
	struct is_invocable_r
	{
		constexpr static bool value = is_invocable_r<Ret, Func, Arg>::value && is_invocable_r<Ret, Func, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename Ret, typename Func, typename... Args>
	struct is_invocable_r<Ret, Func, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_invocable_r<Ret, Func, Args...>::value;
	};

	template<typename Ret, typename Func, typename Arg>
	struct is_invocable_r<Ret, Func, Arg>
	{
		constexpr static bool value = impl::is_invocable_r<Ret, Func, Arg>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename... Args>
	struct is_invocable_r<Ret, wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_invocable_r<Ret, Func, Args...>::value && is_invocable_r<Ret, Funcs..., Args...>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename Arg>
	struct is_invocable_r<Ret, wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_invocable_r<Ret, Func, Arg>::value && is_invocable_r<Ret, Funcs..., Arg>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename Arg, typename... Args>
	struct is_invocable_r<Ret, wrap_type<Func, Funcs...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_invocable_r<Ret, Func, Arg>::value && (is_invocable_r<Ret, Funcs, Args>::value && ...);
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename Arg, typename... Args>
	struct is_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, wrap_type<Arg, Args...>>
	{
		// todo: test **
		constexpr static bool value = is_invocable_r<Ret, Func, Arg>::value && (is_invocable_r<Rets, Funcs, Args>::value && ...);
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename... Args>
	struct is_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test ***
		constexpr static bool value = is_invocable_r<Ret, Func, Args...>::value && is_invocable_r<Rets..., Funcs..., Args...>::value;
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename Arg>
	struct is_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test **
		constexpr static bool value = is_invocable_r<Ret, Func, Arg>::value && is_invocable_r<Rets..., Funcs..., Arg>::value;
	};

	template<typename Ret, typename Func, typename Arg, typename... Args>
	struct is_nothrow_invocable_r
	{
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Arg>::value && is_nothrow_invocable_r<Ret, Func, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename Ret, typename Func, typename... Args>
	struct is_nothrow_invocable_r<Ret, Func, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_nothrow_invocable_r<Ret, Func, Args...>::value;
	};

	template<typename Ret, typename Func, typename Arg>
	struct is_nothrow_invocable_r<Ret, Func, Arg>
	{
		constexpr static bool value = impl::is_nothrow_invocable_r<Ret, Func, Arg>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename... Args>
	struct is_nothrow_invocable_r<Ret, wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Args...>::value && is_nothrow_invocable_r<Ret, Funcs..., Args...>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename Arg>
	struct is_nothrow_invocable_r<Ret, wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Arg>::value && is_nothrow_invocable_r<Ret, Funcs..., Arg>::value;
	};

	template<typename Ret, typename Func, typename... Funcs, typename Arg, typename... Args>
	struct is_nothrow_invocable_r<Ret, wrap_type<Func, Funcs...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Arg>::value && (is_nothrow_invocable_r<Ret, Funcs, Args>::value && ...);
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename Arg, typename... Args>
	struct is_nothrow_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, wrap_type<Arg, Args...>>
	{
		// todo: test **
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Arg>::value && (is_nothrow_invocable_r<Rets, Funcs, Args>::value && ...);
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename... Args>
	struct is_nothrow_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, wrap_type<Args...>>
	{
		// todo: test ***
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Args...>::value && is_nothrow_invocable_r<Rets..., Funcs..., Args...>::value;
	};

	template<typename Ret, typename... Rets, typename Func, typename... Funcs, typename Arg>
	struct is_nothrow_invocable_r<wrap_type<Ret, Rets...>, wrap_type<Func, Funcs...>, Arg>
	{
		// todo: test **
		constexpr static bool value = is_nothrow_invocable_r<Ret, Func, Arg>::value && is_nothrow_invocable_r<Rets..., Funcs..., Arg>::value;
	};

	template<typename T, typename... More>
	struct is_void
	{
		constexpr static bool value = is_void<T>::value && is_void<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_void<T>
	{
		constexpr static bool value = impl::is_void<T>::value;
	};

	template<typename T, typename... More>
	struct is_void<wrap_type<T, More...>>
	{
		constexpr static bool value = is_void<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_null_pointer
	{
		constexpr static bool value = is_null_pointer<T>::value && is_null_pointer<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_null_pointer<T>
	{
		constexpr static bool value = impl::is_null_pointer<T>::value;
	};

	template<typename T, typename... More>
	struct is_null_pointer<wrap_type<T, More...>>
	{
		constexpr static bool value = is_null_pointer<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_integral
	{
		constexpr static bool value = is_integral<T>::value && is_integral<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_integral<T>
	{
		constexpr static bool value = impl::is_integral<T>::value;
	};

	template<typename T, typename... More>
	struct is_integral<wrap_type<T, More...>>
	{
		constexpr static bool value = is_integral<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_floating_point
	{
		constexpr static bool value = is_floating_point<T>::value && is_floating_point<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_floating_point<T>
	{
		constexpr static bool value = impl::is_floating_point<T>::value;
	};

	template<typename T, typename... More>
	struct is_floating_point<wrap_type<T, More...>>
	{
		constexpr static bool value = is_floating_point<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_enum
	{
		constexpr static bool value = is_enum<T>::value && is_enum<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_enum<T>
	{
		constexpr static bool value = impl::is_enum<T>::value;
	};

	template<typename T, typename... More>
	struct is_enum<wrap_type<T, More...>>
	{
		constexpr static bool value = is_enum<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_union
	{
		constexpr static bool value = is_union<T>::value && is_union<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_union<T>
	{
		constexpr static bool value = impl::is_union<T>::value;
	};

	template<typename T, typename... More>
	struct is_union<wrap_type<T, More...>>
	{
		constexpr static bool value = is_union<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_class
	{
		constexpr static bool value = is_class<T>::value && is_class<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_class<T>
	{
		constexpr static bool value = impl::is_class<T>::value;
	};

	template<typename T, typename... More>
	struct is_class<wrap_type<T, More...>>
	{
		constexpr static bool value = is_class<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_function
	{
		constexpr static bool value = is_function<T>::value && is_function<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_function<T>
	{
		constexpr static bool value = impl::is_function<T>::value;
	};

	template<typename T, typename... More>
	struct is_function<wrap_type<T, More...>>
	{
		constexpr static bool value = is_function<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_pointer
	{
		constexpr static bool value = is_pointer<T>::value && is_pointer<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_pointer<T>
	{
		constexpr static bool value = impl::is_pointer<T>::value;
	};

	template<typename T, typename... More>
	struct is_pointer<wrap_type<T, More...>>
	{
		constexpr static bool value = is_pointer<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_lvalue_reference
	{
		constexpr static bool value = is_lvalue_reference<T>::value && is_lvalue_reference<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_lvalue_reference<T>
	{
		constexpr static bool value = impl::is_lvalue_reference<T>::value;
	};

	template<typename T, typename... More>
	struct is_lvalue_reference<wrap_type<T, More...>>
	{
		constexpr static bool value = is_lvalue_reference<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_rvalue_reference
	{
		constexpr static bool value = is_rvalue_reference<T>::value && is_rvalue_reference<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_rvalue_reference<T>
	{
		constexpr static bool value = impl::is_rvalue_reference<T>::value;
	};

	template<typename T, typename... More>
	struct is_rvalue_reference<wrap_type<T, More...>>
	{
		constexpr static bool value = is_rvalue_reference<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_member_object_pointer
	{
		constexpr static bool value = is_member_object_pointer<T>::value && is_member_object_pointer<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_member_object_pointer<T>
	{
		constexpr static bool value = impl::is_member_object_pointer<T>::value;
	};

	template<typename T, typename... More>
	struct is_member_object_pointer<wrap_type<T, More...>>
	{
		constexpr static bool value = is_member_object_pointer<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_member_function_pointer
	{
		constexpr static bool value = is_member_function_pointer<T>::value && is_member_function_pointer<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_member_function_pointer<T>
	{
		constexpr static bool value = impl::is_member_function_pointer<T>::value;
	};

	template<typename T, typename... More>
	struct is_member_function_pointer<wrap_type<T, More...>>
	{
		constexpr static bool value = is_member_function_pointer<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_fundamental
	{
		constexpr static bool value = is_fundamental<T>::value && is_fundamental<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_fundamental<T>
	{
		constexpr static bool value =impl::is_fundamental<T>::value;
	};

	template<typename T, typename... More>
	struct is_fundamental<wrap_type<T, More...>>
	{
		constexpr static bool value = is_fundamental<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_arithmetic
	{
		constexpr static bool value = is_arithmetic<T>::value && is_arithmetic<More...>::value;
	};

	template<typename T>
	struct is_arithmetic<T>
	{
		constexpr static bool value = impl::is_arithmetic<T>::value;
	};

	template<typename T, typename... More>
	struct is_arithmetic<wrap_type<T, More...>>
	{
		constexpr static bool value = is_arithmetic<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_scalar
	{
		constexpr static bool value = is_scalar<T>::value && is_scalar<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_scalar<T>
	{
		constexpr static bool value = impl::is_scalar<T>::value;
	};

	template<typename T, typename... More>
	struct is_scalar<wrap_type<T, More...>>
	{
		constexpr static bool value = is_scalar<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_object
	{
		constexpr static bool value = is_object<T>::value && is_object<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_object<T>
	{
		constexpr static bool value = impl::is_object<T>::value;
	};

	template<typename T, typename... More>
	struct is_object<wrap_type<T, More...>>
	{
		constexpr static bool value = is_object<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_compound
	{
		constexpr static bool value = is_compound<T>::value && is_compound<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_compound<T>
	{
		constexpr static bool value = impl::is_compound<T>::value;
	};

	template<typename T, typename... More>
	struct is_compound<wrap_type<T, More...>>
	{
		constexpr static bool value = is_compound<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_reference
	{
		constexpr static bool value = is_reference<T>::value && is_reference<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_reference<T>
	{
		constexpr static bool value = impl::is_reference<T>::value;
	};

	template<typename T, typename... More>
	struct is_reference<wrap_type<T, More...>>
	{
		constexpr static bool value = is_reference<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_member_pointer
	{
		constexpr static bool value = is_member_pointer<T>::value && is_member_pointer<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_member_pointer<T>
	{
		constexpr static bool value = impl::is_member_pointer<T>::value;
	};

	template<typename T, typename... More>
	struct is_member_pointer<wrap_type<T, More...>>
	{
		constexpr static bool value = is_member_pointer<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_const
	{
		constexpr static bool value = is_const<T>::value && is_const<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_const<T>
	{
		constexpr static bool value = impl::is_const<T>::value;
	};

	template<typename T, typename... More>
	struct is_const<wrap_type<T, More...>>
	{
		constexpr static bool value = is_const<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_volatile
	{
		constexpr static bool value = is_volatile<T>::value && is_volatile<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_volatile<T>
	{
		constexpr static bool value = impl::is_volatile<T>::value;
	};

	template<typename T, typename... More>
	struct is_volatile<wrap_type<T, More...>>
	{
		constexpr static bool value = is_volatile<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_trivial
	{
		constexpr static bool value = is_trivial<T>::value && is_trivial<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_trivial<T>
	{
		constexpr static bool value = impl::is_trivial<T>::value;
	};

	template<typename T, typename... More>
	struct is_trivial<wrap_type<T, More...>>
	{
		constexpr static bool value = is_trivial<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_trivial_copyable
	{
		constexpr static bool value = is_trivial_copyable<T>::value && is_trivial_copyable<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_trivial_copyable<T>
	{
		constexpr static bool value = impl::is_trivially_copyable<T>::value;
	};

	template<typename T, typename... More>
	struct is_trivial_copyable<wrap_type<T, More...>>
	{
		constexpr static bool value = is_trivial_copyable<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_standard_layout
	{
		constexpr static bool value = is_standard_layout<T>::value && is_standard_layout<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_standard_layout<T>
	{
		constexpr static bool value = impl::is_standard_layour<T>::value;
	};

	template<typename T, typename... More>
	struct is_standard_layout<wrap_type<T, More...>>
	{
		constexpr static bool value = is_standard_layout<T, More...>::value;
	};

	template<typename T, typename... More>
	struct has_unique_object_representations
	{
		constexpr static bool value = has_unique_object_representations<T>::value && has_unique_object_representations<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct has_unique_object_representations<T>
	{
		constexpr static bool value = impl::has_unique_object_representations<T>::value;
	};

	template<typename T, typename... More>
	struct has_unique_object_representations<wrap_type<T, More...>>
	{
		constexpr static bool value = has_unique_object_representations<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_empty
	{
		constexpr static bool value = is_empty<T>::value && is_empty<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_empty<T>
	{
		constexpr static bool value = impl::is_empty<T>::value;
	};

	template<typename T, typename... More>
	struct is_empty<wrap_type<T, More...>>
	{
		constexpr static bool value = is_empty<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_polymorphic
	{
		constexpr static bool value = is_polymorphic<T>::value && is_polymorphic<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_polymorphic<T>
	{
		constexpr static bool value = impl::is_polymorphic<T>::value;
	};

	template<typename T, typename... More>
	struct is_polymorphic<wrap_type<T, More...>>
	{
		constexpr static bool value = is_polymorphic<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_abstract
	{
		constexpr static bool value = is_abstract<T>::value && is_abstract<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_abstract<T>
	{
		constexpr static bool value = impl::is_abstract<T>::value;
	};

	template<typename T, typename... More>
	struct is_abstract<wrap_type<T, More...>>
	{
		constexpr static bool value = is_abstract<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_final
	{
		constexpr static bool value = is_final<T>::value && is_final<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_final<T>
	{
		constexpr static bool value = impl::is_final<T>::value;
	};

	template<typename T, typename... More>
	struct is_final<wrap_type<T, More...>>
	{
		constexpr static bool value = is_final<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_aggregate
	{
		constexpr static bool value = is_aggregate<T>::value && is_aggregate<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_aggregate<T>
	{
		constexpr static bool value = impl::is_aggregate<T>::value;
	};

	template<typename T, typename... More>
	struct is_aggregate<wrap_type<T, More...>>
	{
		constexpr static bool value = is_aggregate<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_signed
	{
		constexpr static bool value = is_signed<T>::value && is_signed<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_signed<T>
	{
		constexpr static bool value = impl::is_signed<T>::value;
	};

	template<typename T, typename... More>
	struct is_signed<wrap_type<T, More...>>
	{
		constexpr static bool value = is_signed<T, More...>::value;
	};

	template<typename T, typename... More>
	struct is_unsigned
	{
		constexpr static bool value = is_unsigned<T>::value && is_unsigned<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_unsigned<T>
	{
		constexpr static bool value = impl::is_unsigned<T>::value;
	};

	template<typename T, typename... More>
	struct is_unsigned<wrap_type<T, More...>>
	{
		constexpr static bool value = is_unsigned<T, More...>::value;
	};

	template<typename T, typename Arg, typename... Args>
	struct is_constructible
	{
		constexpr static bool value = is_constructible<T, Arg>::value && is_constructible<T, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T, typename... Args>
	struct is_constructible<T, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_constructible<T, Args...>::value;
	};

	template<typename T, typename Arg>
	struct is_constructible<T, Arg>
	{
		constexpr static bool value = impl::is_constructible<T, Arg>::value;
	};

	template<typename T, typename... Ts, typename... Args>
	struct is_constructible<wrap_type<T, Ts...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_constructible<T, Args...>::value && is_constructible<Ts..., Args...>::value;
	};

	template<typename T, typename... Ts, typename Arg>
	struct is_constructible<wrap_type<T, Ts...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_constructible<T, Arg>::value && is_constructible<Ts..., Arg>::value;
	};

	template<typename T, typename... Ts, typename Arg, typename... Args>
	struct is_constructible<wrap_type<T, Ts...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_constructible<T, Arg>::value && (is_constructible<Ts, Args>::value && ...);
	};

	template<typename T, typename Arg, typename... Args>
	struct is_trivially_constructible
	{
		constexpr static bool value = is_trivially_constructible<T, Arg>::value && is_trivially_constructible<T, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T, typename... Args>
	struct is_trivially_constructible<T, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_trivially_constructible<T, Args...>::value;
	};

	template<typename T, typename Arg>
	struct is_trivially_constructible<T, Arg>
	{
		constexpr static bool value = impl::is_trivially_constructible<T, Arg>::value;
	};

	template<typename T, typename... Ts, typename... Args>
	struct is_trivially_constructible<wrap_type<T, Ts...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_trivially_constructible<T, Args...>::value && is_trivially_constructible<Ts..., Args...>::value;
	};

	template<typename T, typename... Ts, typename Arg>
	struct is_trivially_constructible<wrap_type<T, Ts...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_trivially_constructible<T, Arg>::value && is_trivially_constructible<Ts..., Arg>::value;
	};

	template<typename T, typename... Ts, typename Arg, typename... Args>
	struct is_trivially_constructible<wrap_type<T, Ts...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_trivially_constructible<T, Arg>::value && (is_trivially_constructible<Ts, Args>::value && ...);
	};

	template<typename T, typename Arg, typename... Args>
	struct is_nothrow_constructible
	{
		constexpr static bool value = is_nothrow_constructible<T, Arg>::value && is_nothrow_constructible<T, Args...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T, typename... Args>
	struct is_nothrow_constructible<T, wrap_type<Args...>>
	{
		constexpr static bool value = impl::is_nothrow_constructible<T, Args...>::value;
	};

	template<typename T, typename Arg>
	struct is_nothrow_constructible<T, Arg>
	{
		constexpr static bool value = impl::is_nothrow_constructible<T, Arg>::value;
	};

	template<typename T, typename... Ts, typename... Args>
	struct is_nothrow_constructible<wrap_type<T, Ts...>, wrap_type<Args...>>
	{
		// todo: test **
		constexpr static bool value = is_nothrow_constructible<T, Args...>::value && is_nothrow_constructible<Ts..., Args...>::value;
	};

	template<typename T, typename... Ts, typename Arg>
	struct is_nothrow_constructible<wrap_type<T, Ts...>, Arg>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_constructible<T, Arg>::value && is_nothrow_constructible<Ts..., Arg>::value;
	};

	template<typename T, typename... Ts, typename Arg, typename... Args>
	struct is_nothrow_constructible<wrap_type<T, Ts...>, wrap_type<Arg, Args...>>
	{
		// todo: test *
		constexpr static bool value = is_nothrow_constructible<T, Arg>::value && (is_nothrow_constructible<Ts, Args>::value && ...);
	};

	template<typename T, typename... More>
	struct is_default_constructible
	{
		constexpr static bool value = is_default_constructible<T>::value && is_default_constructible<More...>::value;
		constexpr explicit operator bool(){return value;}
		constexpr bool operator()(){return value;}
	};

	template<typename T>
	struct is_default_constructible<T>
	{
		constexpr static bool value = impl::is_default_constructible<T>::value;
	};

	template<typename T, typename... More>
	struct is_default_constructible<wrap_type<T, More...>>
	{
		constexpr static bool value = is_default_constructible<T, More...>::value;
	};

	template<typename U, typename T, typename... More>
	constexpr bool is_same_v = is_same<U, T, More...>::value;
	template<typename Base, typename Derived, typename... More>
	constexpr bool is_base_of_v = is_base_of<Base, Derived, More...>::value;



	template<typename T, typename... More>
	constexpr bool is_arithmetic_v = is_arithmetic<T, More...>::value;
	template<typename U, typename T, typename... More>
	constexpr bool is_convertible_v = is_convertible<U, T, More...>::value;

}

#endif//GALLIBRARY_TYPE_TRAITS_HPP
