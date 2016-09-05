class Rule
{
	public
		virtual ~Rule() = 0;
		virtual void GetState() =0;
		virtual void AppState() = 0;
}
