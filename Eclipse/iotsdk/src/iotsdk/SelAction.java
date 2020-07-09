package iotsdk;

public abstract class SelAction {
	
	private String name;
	
	public SelAction(String name){
		this.name = name;
	}
	
	public abstract void performAction();
	
	@Override
	public String toString() {
		return name;
	}

}
